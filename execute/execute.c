/*
** execute.c for minishell2 in /home/auzou_t/PSU_2014_minishell2
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sun Nov 30 12:43:47 2014 Thibaud Auzou
** Last update Sun Nov 30 18:12:11 2014 Thibaud Auzou
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int		execute_list(t_list **list,
			     t_env **env,
			     t_paths **paths,
			     t_infos_shell *shell_infos)
{
  t_list	*tmp;

  tmp = *list;
  while (tmp != NULL)
    {
      if (tmp->next != NULL && tmp->next->op == '|')
	tmp = do_pipe(tmp, tmp->next->next, paths, env);
      else if (tmp->next != NULL && (tmp->next->op == '>'
				     || tmp->next->op == '<'
				     || tmp->next->op == '+'
				     || tmp->next->op == '-'))
	tmp = do_redirection(tmp, tmp->next->next, paths, env);
      else
	tmp = do_execute(tmp, paths, env, shell_infos);
    }
  return (0);
}

t_list		*do_execute(t_list *tmp,
			    t_paths **paths,
			    t_env **env,
			    t_infos_shell *shell_infos)
{
  char		*path;
  int		i;

  if ((i = is_built_ins(tmp->command)))
    {
      if (built_ins(tmp, paths, env, i) == ERROR)
	return (NULL);
    }
  else
    {
      if ((path = try_to_access(tmp, paths)) == NULL)
	return (NULL);
      if (execute(tmp->options, path, env) == ERROR)
	return (NULL);
      free(path);
    }
  if (tmp->next == NULL)
    return (NULL);
  if (tmp->next->next != NULL)
    return (tmp->next->next);
  return (NULL);
}

char		*try_to_access(t_list *tmp, t_paths **paths)
{
  char		*path;
  t_paths	*tmp2;

  tmp2 = *paths;
  if (access(tmp->command, F_OK) != -1)
    return (my_strdup(tmp->command));
  while (tmp2 != NULL)
    {
      path = NULL;
      if ((path = build_path(tmp->command, tmp2->path)) == NULL)
	return (NULL);
      if (access(path, F_OK) != -1)
	return (path);
      free(path);
      tmp2 = tmp2->next;
    }
  if (my_putstre(tmp->command) == ERROR)
    exit(EXIT_FAILURE);
  if (my_putstre(": command not found\n") == ERROR)
    exit(EXIT_FAILURE);
  return (NULL);
}

int		execute(char **av, char *com, t_env **env)
{
  char		**tab;
  int		pid;

  tab = list_to_env(env);
  if ((pid = fork()) < 0)
    {
      my_putstre("Could not create new process with fork()\n");
      return (ERROR);
    }
  else if (pid == 0)
    my_execve(com, av, tab);
  else if (my_wait() == ERROR)
    return (ERROR);
  free_wordtab(tab);
  return (0);
}
