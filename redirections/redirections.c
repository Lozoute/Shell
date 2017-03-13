/*
** redirections.c for minishell2 in /home/auzou_t/PSU_2014_minishell2
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sun Nov 30 13:17:00 2014 Thibaud Auzou
** Last update Sun Nov 30 17:56:27 2014 Thibaud Auzou
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

t_list		*do_redirection(t_list *elem1,
				t_list *elem2,
				t_paths **paths,
				t_env **env)
{
  if (elem1->next->op == '>')
    print_in_file(elem1, elem2, paths, env);
  else if (elem1->next->op == '-')
    append_in_file(elem1, elem2, paths, env);
  else if (elem1->next->op == '<')
    read_from_file(elem1, elem2, paths, env);
  else if (elem1->next->op == '+')
    my_putstre("<< not available yet\n");
  if (elem2->next == NULL || elem2->next->next == NULL)
    return (NULL);
  return (elem2->next->next);
}

int			print_in_file(t_list *elem1,
				      t_list *elem2,
				      t_paths **paths,
				      t_env **env)
{
  int			fd;
  int			pid;
  extern t_infos_shell	*shell_infos;
  int			flags;

  flags = O_TRUNC | O_CREAT | O_WRONLY;
  if ((fd = open(elem2->command, flags, S_IRUSR | S_IWUSR)) == -1)
    {
      my_putstre("Could not open\n");
      return (ERROR);
    }
  if ((pid = fork()) == -1)
    {
      my_putstre("Could not fork\n");
      exit(EXIT_FAILURE);
    }
  if (pid == 0)
    {
      my_dup2(fd, 1);
      do_execute(elem1, paths, env, shell_infos);
      exit(EXIT_SUCCESS);
    }
  my_wait();
  close(fd);
  return (0);
}

int			append_in_file(t_list *elem1,
				       t_list *elem2,
				       t_paths **paths,
				       t_env **env)
{
  int			fd;
  int			pid;
  extern t_infos_shell	*shell_infos;
  int			flags;

  flags = O_CREAT | O_WRONLY | O_APPEND;
  if ((fd = open(elem2->command, flags, S_IRUSR | S_IWUSR)) == -1)
    {
      my_putstre("Could not open\n");
      return (ERROR);
    }
  if ((pid = fork()) == -1)
    {
      my_putstre("Could not fork\n");
      exit(EXIT_FAILURE);
    }
  if (pid == 0)
    {
      my_dup2(fd, 1);
      do_execute(elem1, paths, env, shell_infos);
      exit(EXIT_SUCCESS);
    }
  my_wait();
  close(fd);
  return (0);
}

int			read_from_file(t_list *elem1,
				       t_list *elem2,
				       t_paths **paths,
				       t_env **env)
{
  int			fd;
  int			pid;
  extern t_infos_shell	*shell_infos;

  if ((fd = open(elem2->command, O_RDONLY)) == -1)
    {
      my_putstre(elem2->command);
      my_putstre(": no such file or directory\n");
      return (ERROR);
    }
  if ((pid = fork()) == -1)
    {
      my_putstre("Could not fork\n");
      exit(EXIT_FAILURE);
    }
  if (pid == 0)
    {
      my_dup2(fd, 0);
      do_execute(elem1, paths, env, shell_infos);
      exit(EXIT_SUCCESS);
    }
  my_wait();
  close(fd);
  return (0);
}
