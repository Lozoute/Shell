/*
** my_strcat.c for minishell2 in /home/auzou_t/PSU_2014_minishell2/lib
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Wed Nov 26 10:10:50 2014 Thibaud Auzou
** Last update Wed Nov 26 10:13:51 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "my.h"

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;

  if (dest == NULL || src == NULL)
    return (NULL);
  i = my_strlen(dest);
  j = 0;
  while (src[j])
    {
      dest[i] = src[j];
      j = j + 1;
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}
