/*
** add_options.c for minishell2 in /home/auzou_t/PSU_2014_minishell2
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Thu Nov 27 17:43:24 2014 Thibaud Auzou
** Last update Thu Nov 27 18:43:32 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "my.h"

int		add_options(t_list **list, char *str, char *home)
{
  t_list	*tmp;
  char		*option;

  if (check_stx_options(list) == STX_ERR)
    return (STX_ERR);
  tmp = *list;
  while (tmp->next != NULL)
    tmp = tmp->next;
  if ((option = get_command(str)) == NULL)
    return (ERROR);
  if (option[0] == '~' && (option = build_tild(option, home)) == NULL)
    return (ERROR);
  if ((tmp->options = get_options_list(tmp->options, option)) == NULL)
    return (ERROR);
  return (0);
}

int		check_stx_options(t_list **list)
{
  t_list	*tmp;

  tmp = *list;
  if (tmp == NULL)
    {
      if (my_putstre(STX_ERR_MSG))
	return (ERROR);
      return (STX_ERR);
    }
  while (tmp->next != NULL)
    tmp = tmp->next;
  if (tmp->op != '@')
    {
      if (my_putstre(STX_ERR_MSG))
	return (ERROR);
      return (STX_ERR);
    }
  return (0);
}

char		**get_options_list(char **options, char *option)
{
  int		tab_size;
  char		**tab;

  tab_size = options_size(options) + 2;
  tab = NULL;
  if ((tab = my_malloc(tab, (tab_size * sizeof(char *)))) == NULL)
    return (NULL);
  copy_tab(tab, options);
  tab[tab_size - 2] = option;
  tab[tab_size - 1] = NULL;
  if (options != NULL)
    free(options);
  return (tab);
}

int		options_size(char **options)
{
  int		i;

  i = 0;
  while (options != NULL && options[i] != NULL)
    i++;
  return (i);
}

int		copy_tab(char **dest, char **src)
{
  int		i;

  i = 0;
  while (src != NULL && src[i] != NULL)
    {
      dest[i] = NULL;
      dest[i] = src[i];
      dest[i + 1] = NULL;
      i++;
    }
  return (0);
}
