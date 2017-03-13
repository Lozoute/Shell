/*
** print_list.c for minishell2 in /home/auzou_t/PSU_2014_minishell2
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Wed Nov 26 11:22:47 2014 Thibaud Auzou
** Last update Wed Nov 26 11:25:45 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "my.h"

int		print_list(t_env **env)
{
  t_env	*tmp;

  tmp = *env;
  if (tmp == NULL)
    return (0);
  while (tmp != NULL)
    {
      if (my_putstr(tmp->name))
	return (1);
      if (my_putchar(ENV_SEP))
	return (1);
      if (my_putstr(tmp->data))
	return (1);
      if (my_putchar('\n'))
	return (1);
      tmp = tmp->next;
    }
  return (0);
}
