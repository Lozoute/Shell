/*
** env.c for minishell2 in /home/auzou_t/PSU_2014_minishell2
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Wed Nov 26 10:52:49 2014 Thibaud Auzou
** Last update Wed Nov 26 11:42:02 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "my.h"

int		env_to_list(t_env **env, char **environ)
{
  int		i;
  t_env	*elem;
  t_env	*tmp;

  i = 0;
  tmp = *env;
  while (environ != NULL && environ[i] != NULL)
    {
      elem = NULL;
      if ((elem = my_malloc(elem, sizeof(t_env))) == NULL)
	return (1);
      if ((elem->name = get_env_variable_name(environ[i])) == NULL)
	return (1);
      if ((elem->data = get_env_variable_data(environ[i])) == NULL)
	return (1);
      elem->next = NULL;
      if (tmp == NULL)
	*env = elem;
      else
	tmp->next = elem;
      tmp = elem;
      i++;
    }
  return (0);
}

char		*get_env_variable_data(char *str)
{
  int		i;

  i = 0;
  if (str == NULL)
    return (NULL);
  while (str[i]  != '\0' && str[i] != ENV_SEP)
    i++;
  if (str[i] == '\0')
    return (NULL);
  i++;
  return (my_strdup(&(str[i])));
}

char		*get_env_variable_name(char *str)
{
  int		i;

  i = 0;
  if (str == NULL)
    return (NULL);
  while (str[i] != '\0' && str[i] != ENV_SEP)
    i++;
  if (str[i] == '\0')
    return (NULL);
  return (my_strndup(str, i));
}
