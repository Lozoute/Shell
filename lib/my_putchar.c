/*
** my_putchar.c for minishell2 in /home/auzou_t/PSU_2014_minishell2/lib
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Wed Nov 26 10:00:42 2014 Thibaud Auzou
** Last update Wed Nov 26 10:01:15 2014 Thibaud Auzou
*/

#include <unistd.h>
#include "my.h"

int	my_putchar(char c)
{
  if (write(1, &c, 1) == -1)
    return (1);
  return (0);
}
