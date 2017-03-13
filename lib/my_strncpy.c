/*
** my_strncpy.c for minishell2 in /home/auzou_t/PSU_2014_minishell2/lib
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Wed Nov 26 11:14:40 2014 Thibaud Auzou
** Last update Wed Nov 26 11:15:52 2014 Thibaud Auzou
*/

#include "my.h"

char		*my_strncpy(char *dest, char *src, int nb)
{
  int		i;

  i = 0;
  while (i < nb)
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}
