/*
** build_path.c for minishell2 in /home/auzou_t/PSU_2014_minishell2
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Fri Nov 28 10:05:52 2014 Thibaud Auzou
** Last update Fri Nov 28 10:09:47 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "my.h"

char		*build_path(char *com, char *path)
{
  int		size;
  char		*str;

  size = my_strlen(com) + my_strlen(path) + 2;
  str = NULL;
  if ((str = my_malloc(str, sizeof(char) * size)) == NULL)
    return (NULL);
  str = my_strcpy(str, path);
  str = my_strcat(str, "/");
  str = my_strcat(str, com);
  return (str);
}
