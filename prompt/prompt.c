/*
** prompt.c for minishell2 in /home/auzou_t/PSU_2014_minishell2
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Wed Nov 26 18:53:19 2014 Thibaud Auzou
** Last update Wed Nov 26 19:39:32 2014 Thibaud Auzou
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int		print_prompt(t_infos_shell **shell_infos)
{
  if (my_putstr(BLD_BLUE))
    return (1);
  if (my_putstr("[$"))
    return (1);
  if (my_putstr((*shell_infos)->user))
    return (1);
  if (my_putchar('@'))
    return (1);
  if (my_putstr((*shell_infos)->host))
    return (1);
  if (my_putstr(">"))
    return (1);
  if (my_putchar(']'))
    return (1);
  if (my_putstr(CLR_RESET))
    return (1);
  return (0);
}
