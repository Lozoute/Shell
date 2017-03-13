/*
** my_strlen.c for minishell2 in /home/auzou_t/PSU_2014_minishell2/lib
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Wed Nov 26 10:17:15 2014 Thibaud Auzou
** Last update Wed Nov 26 10:17:43 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "my.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str != NULL && str[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}
