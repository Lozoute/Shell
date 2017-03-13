/*
** my_strcmp.c for minishell2 in /home/auzou_t/PSU_2014_minishell2/lib
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Wed Nov 26 10:14:25 2014 Thibaud Auzou
** Last update Wed Nov 26 10:14:38 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "my.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  if (s1 == NULL || s2 == NULL)
    return (0);
  i = 0;
  while (s1[i] != '\0')
    {
      if (s1[i] < s2[i])
	return (-1);
      else if (s1[i] > s2[i])
	return (1);
      if (s2[i] == '\0')
	return (1);
      i = i + 1;
    }
  if (s2[i] != '\0')
    return (-1);
  return (0);
}
