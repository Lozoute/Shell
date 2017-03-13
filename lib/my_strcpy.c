/*
** my_strcpy.c for minishell2 in /home/auzou_t/PSU_2014_minishell2/lib
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Wed Nov 26 10:14:54 2014 Thibaud Auzou
** Last update Wed Nov 26 10:15:25 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "my.h"

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  if (dest == NULL || src == NULL)
    return (NULL);
  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}
