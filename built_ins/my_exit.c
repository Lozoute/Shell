/*
** my_exit.c for minishell2 in /home/auzou_t/PSU_2014_minishell2
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sun Nov 30 18:22:45 2014 Thibaud Auzou
** Last update Sun Nov 30 18:22:46 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "my.h"

int			my_exit(t_list *elem,
				t_paths **paths,
				t_env **env)
{
  extern t_infos_shell	*shell_infos;

  free_env(env);
  free_paths(paths);
  free_infos(&shell_infos);
  free_list(&elem);
  exit(EXIT_SUCCESS);
  return (0);
}
