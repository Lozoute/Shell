/*
** my_unsetenv.c for minishell2 in /home/auzou_t/PSU_2014_minishell2
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sun Nov 30 18:52:26 2014 Thibaud Auzou
** Last update Sun Nov 30 19:01:24 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "my.h"

int		delete_from_env(char **av, t_env **env)
{
  t_env	*tmp;
  int		go;
  t_env	*tmp2;

  go = 0;
  tmp = *env;
  tmp2 = *env;
  while (go == 0 && tmp != NULL)
    {
      if (my_strcmp(av[1], tmp->name) == 0)
	{
	  if (tmp == tmp2)
	    *env = tmp->next;
	  else
	    tmp2->next = tmp->next;
	  free(tmp->name);
	  free(tmp->data);
	  free(tmp);
	  return (1);
	}
      tmp2 = tmp;
      tmp = tmp->next;
    }
  return (go);
}

int	my_unsetenv(char **av, t_env **env)
{
  if (av[1] == NULL)
    {
      my_putstre("unsetenv: missing argument: unsetenv VAR\n");
      return (ERROR);
    }
  if (delete_from_env(av, env) == 0)
    {
      my_putstre("unsetenv: unable to find the entry ");
      my_putstre(av[1]);
      my_putstre("\n");
      return (ERROR);
    }
  return (0);
}
