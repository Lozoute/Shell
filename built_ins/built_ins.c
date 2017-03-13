/*
** built_ins.c for minishell2 in /home/auzou_t/PSU_2014_minishell2
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sun Nov 30 18:10:00 2014 Thibaud Auzou
** Last update Sun Nov 30 19:26:15 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "my.h"

int		built_ins(t_list *elem,
			  t_paths **paths,
			  t_env **env,
			  int i)
{
  if (i == 1)
    my_exit(elem, paths, env);
  else if (i == 2)
    return (my_cd(elem->options, env));
  else if (i == 3)
    return (print_list(env));
  else if (i == 4)
    return (my_setenv(elem->options, env));
  else if (i == 5)
    return (my_unsetenv(elem->options, env));
  return (0);
}

int		is_built_ins(char *str)
{
  if (my_strcmp(str, "exit") == 0)
    return (1);
  if (my_strcmp(str, "cd") == 0)
    return (2);
  if (my_strcmp(str, "env") == 0)
    return (3);
  if (my_strcmp(str, "setenv") == 0)
    return (4);
  if (my_strcmp(str, "unsetenv") == 0)
    return (5);
  return (0);
}
