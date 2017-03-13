/*
** my_strdup.c for minishell2 in /home/auzou_t/PSU_2014_minishell2/lib
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Wed Nov 26 10:15:43 2014 Thibaud Auzou
** Last update Wed Nov 26 10:16:46 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "my.h"

char	*my_strdup(char *src)
{
  int	size;
  char	*str;

  if (src == NULL)
    return (NULL);
  size = my_strlen(src);
  str = NULL;
  if ((str = my_malloc(str, size + 1)) == NULL)
    return (NULL);
  str = my_strcpy(str, src);
  return (str);
}
