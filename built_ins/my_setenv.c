/*
** my_setenv.c for minishell2 in /home/auzou_t/PSU_2014_minishell2
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sun Nov 30 18:33:32 2014 Thibaud Auzou
** Last update Sun Nov 30 19:01:01 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "my.h"

int		change_value_env(char **av, t_env **env)
{
  int		go;
  t_env	*tmp;

  go = 0;
  tmp = *env;
  while (go == 0 && tmp != NULL)
    {
      if (my_strcmp(av[1], tmp->name) == 0)
	{
	  free(tmp->data);
	  tmp->data = NULL;
	  if ((tmp->data = my_strdup(av[2])) == NULL)
	    return (ERROR);
	  go = 1;
	}
      tmp = tmp->next;
    }
  if (go == 0)
    return (enlarge_env(av, env));
  return (0);
}

int		enlarge_env(char **av, t_env **env)
{
  t_env	*tmp;
  t_env	*elem;

  tmp = *env;
  while (tmp != NULL && tmp->next != NULL)
    tmp = tmp->next;
  elem = NULL;
  if ((elem = my_malloc(elem, sizeof(t_env))) == NULL)
    return (ERROR);
  elem->name = my_strdup(av[1]);
  elem->data = my_strdup(av[2]);
  elem->next = NULL;
  if (tmp == NULL)
    *env = elem;
  else
    tmp->next = elem;
  return (0);
}

int	my_setenv(char **av, t_env **env)
{
  if (av[1] == NULL)
    {
      my_putstre("setenv: missing arguments: setenv VAR [value]\n");
      return (ERROR);
    }
  if (av[2] == NULL)
    {
      my_putstre("setenv: please specify a value for ");
      my_putstre(av[1]);
      my_putstre("\nsetenv VAR [value]\n");
      return (ERROR);
    }
  if (change_value_env(av, env) == ERROR)
    return (ERROR);
  return (0);
}
