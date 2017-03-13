/*
** add_operator.c for minishell2 in /home/auzou_t/PSU_2014_minishell2
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Thu Nov 27 15:12:38 2014 Thibaud Auzou
** Last update Thu Nov 27 19:26:49 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "my.h"

int		add_operator(t_list **list, char *str)
{
  t_list	*tmp;
  t_list	*elem;

  tmp = *list;
  while (tmp != NULL && tmp->next != NULL)
    tmp = tmp->next;
  if (tmp == NULL || check_stx_op(str) == STX_ERR || tmp->op != '@')
    {
      if (my_putstre(STX_ERR_MSG))
	return (ERROR);
      return (STX_ERR);
    }
  elem = NULL;
  if ((elem = my_malloc(elem, sizeof(t_list))) == NULL)
    return (ERROR);
  elem->command = NULL;
  elem->options = NULL;
  elem->next = NULL;
  elem->op = str[0];
  tmp->next = elem;
  return (0);
}

int		check_stx_op(char *str)
{
  int		i;

  i = 1;
  if (str[i] == '<' && str[i - 1] == '<')
    {
      str[i - 1] = '+';
      str[i] = ' ';
      return (0);
    }
  if (str[i] == '>' && str[i - 1] == '>')
    {
      str[i] = ' ';
      str[i - 1] = '-';
      return (0);
    }
  while (str[i] && (str[i] == SHELL_SEP || str[i] == SHELL_SEP_2))
    i++;
  if (str[i] == '\0' || str[i] == '-')
    return (STX_ERR);
  if (is_command_sep(str[i], COMMAND_SEP))
    return (STX_ERR);
  return (0);
}
