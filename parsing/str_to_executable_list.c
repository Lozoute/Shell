/*
** str_to_executable_list.c for minishell2 in /home/auzou_t/PSU_2014_minishell2
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Thu Nov 27 14:31:40 2014 Thibaud Auzou
** Last update Thu Nov 27 19:05:12 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "my.h"

int		str_to_executable_list(t_list **list, char *str, char *home)
{
  int		i;
  int		err;
  int		sep;

  sep = 1;
  i = 0;
  while (str != NULL && str[i] != '\0')
    {
      if (str[i] != SHELL_SEP && str[i] != SHELL_SEP_2)
	{
	  err = add_it_to_list(list, &(str[i]), home, &sep);
	  if (err == ERROR || err == STX_ERR)
	    return (err);
	  while (str[i] != SHELL_SEP
		 && str[i] != SHELL_SEP_2
		 && str[i] != '\0'
		 && !is_command_sep(str[++i], COMMAND_SEP)
		 && sep == 0);
	}
      else
	i++;
    }
  return (0);
}

int		add_it_to_list(t_list **list, char *str, char *home, int *sep)
{
  if (is_command_sep(str[0], COMMAND_SEP))
    {
      *sep = 1;
      return (add_operator(list, str));
    }
  if (*sep == 1)
    {
      *sep = 0;
      return (add_command(list, str));
    }
  else
    {
      return (add_options(list, str, home));
    }
}

int		is_command_sep(char c, char *command_sep)
{
  int		i;

  i = 0;
  while (command_sep[i])
    {
      if (command_sep[i] == c)
	return (i + 1);
      i++;
    }
  return (0);
}

