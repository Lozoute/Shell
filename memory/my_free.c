/*
** my_free.c for minishell2 in /home/auzou_t/PSU_2014_minishell2
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Fri Nov 28 09:48:59 2014 Thibaud Auzou
** Last update Fri Nov 28 09:49:02 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "my.h"

void		free_env(t_env **env)
{
  t_env	*tmp;
  t_env	*tmp2;

  tmp = *env;
  while (tmp != NULL)
    {
      tmp2 = tmp;
      if (tmp->name != NULL)
	free(tmp->name);
      tmp->name = NULL;
      if (tmp->data != NULL)
	free(tmp->data);
      tmp->data = NULL;
      tmp = tmp2->next;
      free(tmp2);
    }
  *env = NULL;
}

void		free_paths(t_paths **paths)
{
  t_paths	*tmp;
  t_paths	*tmp2;

  tmp = *paths;
  while (tmp != NULL)
    {
      tmp2 = tmp;
      if (tmp->path != NULL)
	free(tmp->path);
      tmp->path = NULL;
      tmp = tmp2->next;
      free(tmp2);
    }
  *paths = NULL;
}

void			free_infos(t_infos_shell **infos_shell)
{
  t_infos_shell	*tmp;

  tmp = *infos_shell;
  if (tmp != NULL)
    free(tmp);
  *infos_shell = NULL;
}

void		free_list(t_list **list)
{
  int		i;
  t_list	*tmp;
  t_list	*tmp2;

  tmp = *list;
  while (tmp != NULL)
    {
      i = 0;
      tmp2 = tmp;
      while (tmp->options != NULL && tmp->options[i] != NULL)
	{
	  free(tmp->options[i]);
	  i++;
	}
      if (tmp->options != NULL)
	free(tmp->options);
      tmp->options = NULL;
      tmp = tmp2->next;
      free(tmp2);
    }
  *list = NULL;
}

void		free_wordtab(char **tab)
{
  int		i;

  i = 0;
  while (tab != NULL && tab[i] != NULL)
    {
      free(tab[i]);
      tab[i] = NULL;
      i++;
    }
  if (tab != NULL)
    free(tab);
  tab = NULL;
}
