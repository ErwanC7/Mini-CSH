##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile of linked_list
##

NAME		=	liblist.a

SRC			=	sources/add.c \
				sources/del.c \
				sources/free_list.c \
				sources/list_len.c

OBJ			=	$(SRC:.c=.o)

CC			=	gcc

CPPFLAGS	=	-iquote include/

CFLAGS		=	-W -Wall -Wextra

all :	$(NAME)

$(NAME) :	$(OBJ)
	ar rc $(NAME) $(OBJ)

debug : CFLAGS += -g3
debug : re

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY :	all clean fclean re