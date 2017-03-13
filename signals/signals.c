/*
** signals.c for minishell2 in /home/auzou_t/PSU_2014_minishell2
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sat Nov 29 20:01:26 2014 Thibaud Auzou
** Last update Sun Nov 30 20:16:42 2014 Thibaud Auzou
*/

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "my.h"

void		ctrl_c_kill(int sig)
{
  exit(EXIT_SUCCESS);
}

void			ctrl_c_prompt(int sig)
{
  extern t_infos_shell	*shell_infos;

  if (write(1, "\n", 2) == -1)
    exit(EXIT_FAILURE);
  if (print_prompt(&shell_infos) == ERROR)
    exit(EXIT_FAILURE);
}
