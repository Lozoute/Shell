##
## Makefile for minishell2 in /home/auzou_t/PSU_2014_minishell2
## 
## Made by Thibaud Auzou
## Login   <auzou_t@epitech.net>
## 
## Started on  Wed Nov 26 11:37:14 2014 Thibaud Auzou
## Last update Sun Nov 30 20:16:55 2014 Thibaud Auzou
##

CC		= gcc

RM		= rm -f

CFLAGS		+= -Wextra -Wall -Werror -Wno-unused-parameter
CFLAGS		+= -ansi -pedantic
CFLAGS		+= -I./include/ -I../include/ -D_BSD_SOURCE

LDFLAGS	= -lmy -L./lib/

NAME		= mysh

SRCS		= main.c \
		  env/env_to_list.c \
		  env/get_paths_from_env.c \
		  env/get_infos_from_env.c \
		  env/list_to_env.c \
		  system_calls/system_calls.c \
		  tild/tild.c \
		  path/build_path.c \
		  list/print_list.c \
		  memory/my_free.c \
		  memory/my_malloc.c \
		  prompt/prompt.c \
		  parsing/str_to_executable_list.c \
		  parsing/add_operator.c \
		  parsing/add_command.c \
		  parsing/add_options.c \
		  signals/signals.c \
		  execute/execute.c \
		  pipe/pipe.c \
		  redirections/redirections.c \
		  built_ins/built_ins.c \
		  built_ins/my_exit.c \
		  built_ins/my_setenv.c \
		  built_ins/my_unsetenv.c \
		  built_ins/my_cd.c \
		  built_ins/dots.c

OBJS		= $(SRCS:.c=.o)

MAKELIB	= make -C lib/

CLEANLIB	= make clean -C lib/

FCLEANLIB	= make fclean -C lib/


all: $(NAME)

$(NAME): $(OBJS)
		$(MAKELIB)
		$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
		$(RM) $(OBJS)
		$(CLEANLIB)

fclean: clean
		$(RM) $(NAME)
		$(FCLEANLIB)

re: fclean all

.PHONY: all clean fclean re
