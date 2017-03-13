/*
** get_next_line.c for get_next_line in /home/auzou_t/CPE_2014_get_next_line
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Mon Nov 17 09:32:01 2014 Thibaud Auzou
** Last update Sat Nov 29 16:01:55 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

static char	*save = NULL;

char		*get_next_line(const int fd)
{
  char		*buff;
  int		nbytes;
  char		*str;
  int		ok;

  if ((buff = malloc(sizeof(char) * (READ_SIZE + 1))) == NULL)
    return (NULL);
  ok = 1;
  while ((str = cut_save(&ok, 0, 0, 0)) == NULL && ok)
    {
      if ((nbytes = read(fd, buff, READ_SIZE)) == -1)
	return (NULL);
      if (nbytes == 0)
	{
	  free(buff);
	  if (save != NULL && save[0] == '\0')
	    return (NULL);
	  return (cut_save(&ok, 1, 0, 0));
	}
      buff[nbytes] = '\0';
      if (add_to_save(buff))
	return (NULL);
    }
  free(buff);
  return (str);
}

int		len(char *str)
{
  int		i;

  i = 0;
  while (str != NULL && str[i] != '\0')
    i++;
  return (i);
}

int		add_to_save(char *buff)
{
  char		*n_save;
  int		i;
  int		j;

  n_save = NULL;
  if ((n_save = malloc((sizeof(char)) * (len(buff) + len(save) + 1))) == NULL)
    return (1);
  i = 0;
  j = 0;
  while (save != NULL && save[i] != '\0')
    {
      n_save[i] = save[i];
      i++;
    }
  while (buff[j] != '\0')
    n_save[i++] = buff[j++];
  n_save[i] = '\0';
  if (save != NULL)
    free(save);
  save = n_save;
  return (0);
}

int		remove_from_save(int *ok, int i)
{
  static char	*n_save;
  int		j;

  n_save = NULL;
  if (save[i] == '\0')
    {
      free(save);
      save = NULL;
      return (0);
      i--;
    }
  if ((n_save = malloc(sizeof(char) * (len(save) - i))) == NULL)
    {
      *ok = 0;
      return (1);
    }
  i++;
  j = 0;
  while (save[i])
    n_save[j++] = save[i++];
  n_save[j] = '\0';
  free(save);
  save = n_save;
  return (0);
}

char		*cut_save(int *ok, int force_cutting, int i, int j)
{
  char		*str;

  if (save == NULL)
    return (NULL);
  str = NULL;
  while (save[i] != '\0' && save[i] != '\n')
    i++;
  if (save[i] == '\0' && !force_cutting)
    return (NULL);
  if ((str = malloc((len(save) + 1) * sizeof(char))) == NULL)
    {
      *ok = 0;
      return (NULL);
    }
  while (j < i)
    {
      str[j] = save[j];
      j++;
    }
  str[j] = '\0';
  if (remove_from_save(ok, i))
    return (NULL);
  return (str);
}
