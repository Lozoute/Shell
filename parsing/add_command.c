/*
** add_command.c for minishell2 in /home/auzou_t/PSU_2014_minishell2
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Thu Nov 27 15:27:06 2014 Thibaud Auzou
** Last update Thu Nov 27 18:10:35 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "my.h"

int		add_command(t_list **list, char *str)
{
  t_list	*tmp;
  t_list	*elem;

  tmp = *list;
  if (check_stx_command(list) == STX_ERR)
    return (STX_ERR);
  while (tmp != NULL && tmp->next != NULL)
    tmp = tmp->next;
  elem = NULL;
  if ((elem = my_malloc(elem, sizeof(t_list))) == NULL)
    return (ERROR);
  if ((elem->command = get_command(str)) == NULL)
    return (ERROR);
  if ((elem->options = get_options_list(NULL, elem->command)) == NULL)
    return (ERROR);
  elem->op =  '@';
  elem->next = NULL;
  if (tmp == NULL)
    *list = elem;
  else
    tmp->next = elem;
  return (0);
}

int		check_stx_command(t_list **list)
{
  t_list	*tmp;

  tmp = *list;
  if (tmp == NULL)
    return (0);
  while (tmp->next != NULL)
    tmp = tmp->next;
  if (tmp->command != NULL)
    {
      if (my_putstre(STX_ERR_MSG))
	return (ERROR);
      return (STX_ERR);
    }
  return (0);
}

char		*get_command(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0'
	 && str[i] != SHELL_SEP
	 && str[i] != SHELL_SEP_2
	 && !is_command_sep(str[i], COMMAND_SEP))
    i++;
  return (my_strndup(str, i));
}
