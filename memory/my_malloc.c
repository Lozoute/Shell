/*
** my_malloc.c for minishell2 in /home/auzou_t/PSU_2014_minishell2
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Fri Nov 28 09:42:31 2014 Thibaud Auzou
** Last update Fri Nov 28 09:42:54 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "my.h"

void		*my_malloc(void *data, int size)
{
  data = NULL;
  data = malloc(size);
  if (data == NULL)
    {
      my_putstre("Unable to malloc\n");
      return (NULL);
    }
  return (data);
}
