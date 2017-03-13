##
## Makefile for libmy in /home/auzou_t/PSU_2014_minishell2/lib
## 
## Made by Thibaud Auzou
## Login   <auzou_t@epitech.net>
## 
## Started on  Wed Nov 26 09:59:07 2014 Thibaud Auzou
## Last update Sun Nov 30 20:17:15 2014 Thibaud Auzou
##

CC	= gcc

AR	= ar rc

NAME	= libmy.a

CFLAGS	+= -Wextra -Wall -Werror
CFLAGS	+= -ansi -pedantic
CFLAGS	+= -I../include/

SRC	= my_putchar.c \
	  my_put_nbr.c \
	  my_putstr.c \
	  my_strlen.c \
	  my_strcpy.c \
	  my_strncpy.c \
	  my_strcat.c \
	  my_putstre.c \
	  my_strncmp.c \
	  my_strcmp.c \
	  my_strdup.c \
	  my_strndup.c \
	  get_next_line.c

OBJS	= $(SRC:.c=.o)

RM	= rm -f


all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean
