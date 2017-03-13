/*
** my_strncmp.c for minishell2 in /home/auzou_t/PSU_2014_minishell2/lib
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Wed Nov 26 10:17:57 2014 Thibaud Auzou
** Last update Wed Nov 26 10:18:08 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "my.h"

int	my_strncmp(char *s1, char *s2, int nb)
{
  int	i;

  if (s1 == NULL || s2 == NULL || nb == 0)
    return (0);
  if (nb < 0)
    nb = nb * - 1;
  i = 0;
  while (s1[i] != '\0' && i < nb && s2[i] != '\n')
    {
      if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
      i = i + 1;
    }
  return (0);
}
