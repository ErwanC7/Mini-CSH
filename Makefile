##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile of minishell2
##

NAME		=	mysh

MAIN		=	sources/main.c

SRC			=	sources/minishell.c \
				sources/pathing.c \
				sources/get_command.c \
				sources/environment.c \
				sources/builtin/change_directory.c \
				sources/builtin/env.c \
				sources/builtin/exit.c \
				sources/builtin/redirection.c

OBJ			=	$(SRC:.c=.o) \
				$(MAIN:.c=.o)

CPPFLAGS	= 	-iquote include/ -iquote lib/my/include/ -iquote lib/list/include/

CFLAGS		= 	-W -Wall -Wextra

LDFLAGS		=	-L lib/my/ -lmy -L lib/list/ -llist

CC			=	gcc

all :	$(NAME)

$(NAME) :	$(OBJ)
	$(MAKE) -sC lib/my/
	$(MAKE) -sC lib/list/
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

debug : CFLAGS += -g3
debug : re
	$(MAKE) debug -sC lib/my/
	$(MAKE) debug -sC lib/list/

clean :
	$(MAKE) clean -sC lib/my/
	$(MAKE) clean -sC lib/list/
	$(RM) $(OBJ)

fclean :	clean
	$(MAKE) fclean -sC lib/my/
	$(MAKE) fclean -sC lib/list/
	$(RM) $(NAME)

re :	fclean all

.PHONY : all debug clean fclean re
