/*
** get_infos_from_env.c for minishell2 in /home/auzou_t/PSU_2014_minishell2
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Wed Nov 26 17:07:10 2014 Thibaud Auzou
** Last update Wed Nov 26 17:41:09 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "my.h"

int			get_infos_from_env(t_env **env,
					   t_infos_shell **shell_infos)
{
  t_env		*tmp;
  int			i;
  t_infos_shell	*elem;

  tmp = *env;
  elem = NULL;
  if ((elem = my_malloc(elem, sizeof(t_infos_shell))) == NULL)
    return (1);
  init_infos(elem);
  *shell_infos = elem;
  while (tmp != NULL)
    {
      if ((i = infos_name_is_matching(tmp->name)))
	{
	  if (set_this_infos(shell_infos, tmp->data, i))
	    return (1);
	}
      tmp = tmp->next;
    }
  return (0);
}

int		init_infos(t_infos_shell *elem)
{
  elem->pwd = NULL;
  elem->oldpwd = NULL;
  elem->host = NULL;
  elem->home = NULL;
  elem->user = NULL;
  return (0);
}

int		infos_name_is_matching(char *str)
{
  if (my_strcmp(str, "PWD") == 0)
    return (1);
  if (my_strcmp(str, "OLDPWD") == 0)
    return (2);
  if (my_strcmp(str, "HOST") == 0)
    return (3);
  if (my_strcmp(str, "HOME") == 0)
    return (4);
  if (my_strcmp(str, "USER") == 0)
    return (5);
  return (0);
}

int		set_this_infos(t_infos_shell **shell_infos, char *data, int i)
{
  if (i == 1)
    (*shell_infos)->pwd = data;
  else if (i == 2)
    (*shell_infos)->oldpwd = data;
  else if (i == 3)
    (*shell_infos)->host = data;
  else if (i == 4)
    (*shell_infos)->home = data;
  else if (i == 5)
    (*shell_infos)->user = data;
  return (0);
}
