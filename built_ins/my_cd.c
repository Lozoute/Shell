/*
** my_cd.c for minishell2 in /home/auzou_t/PSU_2014_minishell2
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sun Nov 30 18:25:55 2014 Thibaud Auzou
** Last update Sun Nov 30 20:10:06 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int	my_cd(char **av, t_env **env)
{
  if (av[1] == NULL)
    {
      my_putstre("usage: cd [directory path]\n");
      return (ERROR);
    }
  if (chdir(av[1]) == -1)
    {
      my_putstre("cd: not a directory or permission denied\n");
      return (ERROR);
    }
  change_pwd(av[1], env);
  return (0);
}

int		change_pwd(char *path, t_env **env)
{
  t_env	*tmp;
  char		*save;
  int		go;
  char		*pwd;

  go = 1;
  tmp = *env;
  while (go == 1 && tmp != NULL)
    {
      if (my_strcmp(tmp->name, ENV_PWD) == 0)
	{
	  save = tmp->data;
	  pwd = build_pwd(path, save);
	  tmp->data = pwd;
	  go = 0;
	  change_old_pwd(save, env);
	}
      tmp=tmp->next;
    }
  return (0);
}

int		change_old_pwd(char *save, t_env **env)
{
  t_env	*tmp;

  tmp = *env;
  while (tmp != NULL)
    {
      if (my_strcmp(tmp->name, ENV_OLDPWD) == 0)
	{
	  free(tmp->data);
	  tmp->data = NULL;
	  tmp->data = save;
	  return (0);
	}
      tmp = tmp->next;
    }
  return (0);
}

char	*build_pwd(char *str, char *save)
{
  char	*tmp;
  int	size;

  if (str[my_strlen(str) - 1] == '/' && my_strlen(str) != 1)
    str[my_strlen(str) - 1] = '\0';
  if (str[0] == '/')
    return (my_strdup(str));
  if (str[0] != '.')
    {
      size = my_strlen(save) + my_strlen(str) + 2;
      tmp = NULL;
      if ((tmp = my_malloc(tmp, sizeof(char) * size)) == NULL)
	return (NULL);
      tmp = my_strcpy(tmp, save);
      tmp = my_strcat(tmp, "/");
      return (my_strcat(tmp, str));
    }
  return (build_pwd_with_dots(str, save));
}

char	*build_pwd_with_dots(char *str, char *pwd)
{
  char	*new_pwd;
  int	i;

  i = 0;
  new_pwd = my_strdup(pwd);
  while (str[i] != '\0')
    {
      if (str[0] == '.' && str[1] == '.')
	{
	  go_to_parent(new_pwd);
	  (str[2] == '/') ? (str = &(str[3])) : (str = &(str[2]));
	}
      else if (str[0] == '.')
	(str[1] == '/') ? (str = &(str[2])) : (str = &(str[1]));
      else
	{
	  new_pwd = add_path_to_pwd(str, new_pwd);
	  str = &(str[word_size(str)]);
	  if (str[0] == '/')
	    str = &(str[1]);
	}
    }
  return (new_pwd);
}
