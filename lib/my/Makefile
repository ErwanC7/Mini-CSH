##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile of lib
##

NAME	=	libmy.a

SRC		=	sources/my_putstr.c	\
			sources/my_concat.c	\
			sources/my_strcmp.c	\
			sources/my_strlen.c	\
			sources/my_strdup.c	\
			sources/clean_str.c	\
			sources/my_str_to_word_array.c

OBJ		=	$(SRC:.c=.o)

CFLAGS	= 	-W -Wall -Wextra

CC		=	gcc

all :	$(NAME)

$(NAME) :	$(OBJ)
	ar rc $(NAME) $(OBJ)

debug :	CFLAGS += -g3
debug :	re

clean :
	$(RM) $(OBJ)

fclean :	clean
		$(RM) $(NAME)

re :	fclean all

.PHONY : all clean fclean re
