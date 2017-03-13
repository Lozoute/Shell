/*
** main.c for minishell2 in /home/auzou_t/PSU_2014_minishell2
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Wed Nov 26 10:48:15 2014 Thibaud Auzou
** Last update Sun Nov 30 12:54:01 2014 Thibaud Auzou
*/

#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

t_infos_shell	*shell_infos = NULL;

int		main(int argc, char **argv, char **environ)
{
  t_env	*env;
  t_paths	*paths;

  if (signal(SIGINT, ctrl_c_prompt) == SIG_ERR)
    return (1);
  paths = NULL;
  env = NULL;
  if (env_to_list(&env, environ) == ERROR)
    return (ERROR);
  if (get_paths_from_env(&env, &paths) == ERROR)
    return (ERROR);
  if (get_infos_from_env(&env, &shell_infos) == ERROR)
    return (ERROR);
  if (minishell(&env, &paths) == ERROR)
    return (ERROR);
  free_env(&env);
  free_paths(&paths);
  free_infos(&shell_infos);
  my_putchar('\n');
  return (0);
}

int		minishell(t_env **env, t_paths **paths)
{
  char		*buff;
  t_list	*list;
  int		err;
  char		*home;

  if (print_prompt(&shell_infos) == ERROR)
    return (ERROR);
  home = shell_infos->home;
  while ((buff = get_next_line(STDIN)) != NULL)
    {
      list = NULL;
      if ((err = str_to_executable_list(&list, buff, home)) == ERROR)
	return (ERROR);
      if (err != STX_ERR && list != NULL)
	{
	  if (execute_list(&list, env, paths, shell_infos) == ERROR)
	    return (ERROR);
	}
      free_list(&list);
      free(buff);
      if (print_prompt(&shell_infos) == ERROR)
	return (ERROR);
    }
  return (0);
}
