/*
** my_putstre.c for minishell2 in /home/auzou_t/PSU_2014_minishell2/lib
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Wed Nov 26 10:07:58 2014 Thibaud Auzou
** Last update Wed Nov 26 10:09:17 2014 Thibaud Auzou
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int	my_putstre(char *str)
{
  if (str == NULL)
    return (0);
  if (write(2, str, my_strlen(str)) == -1)
    return (1);
  return (0);
}
