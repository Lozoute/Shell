/*
** dots.c for minishell1 in /home/auzou_t/rendu/PSU/PSU_2014_minishell1
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sat Nov  8 22:45:46 2014 Thibaud Auzou
** Last update Sun Nov 30 20:10:30 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include <my.h>

void	go_to_parent(char *str)
{
  int	i;

  i = my_strlen(str) - 1;
  while (str[i] != '/')
    {
      str[i] = '\0';
      i = i - 1;
    }
  if (i != 0)
    str[i] = '\0';
}

int	word_size(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0' && str[i] != '/')
    i = i + 1;
  return (i);
}

void	concat_path_with_pwd(char *tmp, char *pwd, char *str, int size)
{
  int	i;
  int	j;

  i = 0;
  while (tmp[i])
    {
      pwd[i] = tmp[i];
      i = i + 1;
    }
  j = 0;
  while (j < size)
    {
      pwd[i] = str[j];
      i = i + 1;
      j = j + 1;
    }
  pwd[i] = '\0';
}

char	*add_path_to_pwd(char *str, char *pwd)
{
  int	size;
  int	pwd_size;
  char	*tmp;

  size = 0;
  tmp = NULL;
  tmp = my_malloc(tmp, my_strlen(pwd) + 2);
  tmp = my_strcat(pwd, "/");
  free(pwd);
  pwd = tmp;
  while (str[size] != '\0' && str[size] != '/')
    size = size + 1;
  pwd_size = my_strlen(pwd);
  tmp = my_strdup(pwd);
  free(pwd);
  pwd = NULL;
  pwd = my_malloc(pwd, size + pwd_size + 1);
  concat_path_with_pwd(tmp, pwd, str, size);
  return (pwd);
}
