/*
** get_paths_from_env.c for minishell2 in /home/auzou_t/PSU_2014_minishell2
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Wed Nov 26 15:20:21 2014 Thibaud Auzou
** Last update Wed Nov 26 17:04:56 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "my.h"

int		get_paths_from_env(t_env **env, t_paths **paths)
{
  t_env	*tmp1;
  int		stop;

  tmp1 = *env;
  stop = 0;
  while (tmp1 != NULL && !stop)
    {
      if (my_strcmp(tmp1->name, ENV_PATHS) == 0)
	{
	  if (create_paths_list(tmp1->data, paths))
	    return (1);
	  stop = 1;
	}
      tmp1 = tmp1->next;
    }
  return (0);
}

int		create_paths_list(char *str, t_paths **paths)
{
  t_paths	*elem;
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (str != NULL && j != -1)
    {
      if (str[i] == PATH_SEP || str[i] == '\0')
	{
	  elem = NULL;
	  if ((elem = my_malloc(elem, sizeof(t_paths))) == NULL)
	    return (1);
	  if ((elem->path = my_strndup(&(str[j]), i - j)) == NULL)
	    return (1);
	  j = i + 1;
	  elem->next = *paths;
	  *paths = elem;
	  if (str[i] == '\0')
	    j = -1;
	}
      i++;
    }
  return (0);
}
