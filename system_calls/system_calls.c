/*
** system_calls.c for minishell2 in /home/auzou_t/PSU_2014_minishell2
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sun Nov 30 12:56:00 2014 Thibaud Auzou
** Last update Sun Nov 30 14:33:00 2014 Thibaud Auzou
*/

#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

void	my_execve(char *com, char **av, char **tab)
{
  if (execve(com, av, tab) == -1)
    {
      my_putstre(com);
      my_putstre(": command not found\n");
      exit(EXIT_FAILURE);
    }
}

int	my_wait(void)
{
  int	status;

  wait(&status);
  if (status < 0)
    {
      my_putstre("A problem occured with wait() system call\n");
      exit(EXIT_FAILURE);
    }
  return (0);
}

int	my_pipe(int pipefd[2])
{
  if (pipe(pipefd) == -1)
    {
      my_putstre("Unable to create pipe\n");
      exit(EXIT_FAILURE);
    }
  return (0);
}

int	my_dup(int fd)
{
  if (dup(fd) == -1)
    {
      my_putstre("Unable to dup\n");
      exit(EXIT_FAILURE);
    }
  return (0);
}

int	my_dup2(int fd1, int fd2)
{
  if (dup2(fd1, fd2) == -1)
    {
      my_putstre("Unable to dup2\n");
      exit(EXIT_FAILURE);
    }
  return (0);
}
