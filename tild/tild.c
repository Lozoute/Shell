/*
** tild.c for minishell2 in /home/auzou_t/PSU_2014_minishell2
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Thu Nov 27 17:18:24 2014 Thibaud Auzou
** Last update Fri Nov 28 10:07:34 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "my.h"

char		*build_tild(char *str, char *home)
{
  int		size;
  char		*path;

  if (home == NULL)
    return (str);
  size = my_strlen(str) + my_strlen(home) + 1;
  path = NULL;
  if ((path = my_malloc(path, (size * sizeof(char)))) == NULL)
    return (NULL);
  path = my_strcpy(path, home);
  path = my_strcat(path, &(str[1]));
  free (str);
  return (path);
}
