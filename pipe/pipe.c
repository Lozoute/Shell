/*
** pipe.c for minishell2 in /home/auzou_t/PSU_2014_minishell2
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sat Nov 29 23:10:35 2014 Thibaud Auzou
** Last update Sun Nov 30 17:53:23 2014 Thibaud Auzou
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

t_list		*do_pipe(t_list *elem1,
			 t_list *elem2,
			 t_paths **paths,
			 t_env **env)
{
  int		pipefd[2];
  int		pid;

  my_pipe(pipefd);
  pid = fork();
  if (pid == 0)
    writting_son(pipefd, elem1, paths, env);
  (pid == -1) ? (pid = -1) : (pid = fork());
  if (pid == 0)
    reading_son(pipefd, elem2, paths, env);
  if (pid == -1)
    {
      my_putstre("Unable to fork\n");
      exit(EXIT_FAILURE);
    }
  close(pipefd[0]);
  close(pipefd[1]);
  my_wait();
  my_wait();
  if (elem2->next == NULL || elem2->next->next == NULL)
    return (NULL);
  return (elem2->next->next);
}

void			writting_son(int pipefd[2],
				     t_list *elem,
				     t_paths **paths,
				     t_env **env)
{
  extern t_infos_shell	*shell_infos;

  close(pipefd[0]);
  my_dup2(pipefd[1], 1);
  do_execute(elem, paths, env, shell_infos);
  close(pipefd[1]);
  exit(EXIT_SUCCESS);
}

void			reading_son(int pipefd[2],
				    t_list *elem,
				    t_paths **paths,
				    t_env **env)
{
  extern t_infos_shell	*shell_infos;

  close(pipefd[1]);
  my_dup2(pipefd[0], 0);
  do_execute(elem, paths, env, shell_infos);
  close(pipefd[0]);
  exit(EXIT_SUCCESS);
}
