/*
** my_strndup.c for minishell2 in /home/auzou_t/PSU_2014_minishell2/lib
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Wed Nov 26 11:10:07 2014 Thibaud Auzou
** Last update Wed Nov 26 11:36:11 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "my.h"

char		*my_strndup(char *src, int nb)
{
  char		*str;

  if (src == NULL)
    return (NULL);
  str = NULL;
  if ((str = my_malloc(str, sizeof(char) * (nb + 1))) == NULL)
    return (NULL);
  str = my_strncpy(str, src, nb);
  return (str);
}
