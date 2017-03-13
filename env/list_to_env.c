/*
** list_to_env.c for minishell2 in /home/auzou_t/PSU_2014_minishell2
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Fri Nov 28 09:52:59 2014 Thibaud Auzou
** Last update Fri Nov 28 10:24:38 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "my.h"

char		**list_to_env(t_env **env)
{
  t_env	*tmp;
  int		tab_size;
  char		**tab;

  if (env == NULL || *env == NULL)
    return (NULL);
  tmp = *env;
  tab_size = 1;
  while (tmp != NULL)
    {
      tmp = tmp->next;
      tab_size++;
    }
  tab = NULL;
  if ((tab = my_malloc(tab, (sizeof(char *) * tab_size))) == NULL)
    return (NULL);
  return (copy_list_in_env(tab, env));
}

char		**copy_list_in_env(char **tab, t_env **env)
{
  t_env	*tmp;
  int		i;
  int		size;
  char		*str;

  i = 0;
  tmp = *env;
  while (tmp != NULL)
    {
      size = my_strlen(tmp->name) + my_strlen(tmp->data) + 2;
      str = NULL;
      if ((str = my_malloc(str, sizeof(char) * size)) == NULL)
	return (NULL);
      str = my_strcpy(str, tmp->name);
      str = my_strcat(str, "=");
      str = my_strcat(str, tmp->data);
      tab[i] = str;
      tab[i + 1] = NULL;
      i++;
      tmp = tmp->next;
    }
  return (tab);
}
