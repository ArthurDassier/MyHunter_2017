##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

SRC	=	srcs/brain.c		\
		srcs/basics.c		\
		srcs/oaso.c		\
		srcs/fcts_while.c	\
		srcs/init_wind.c	\

OBJ	=	$(SRC:.c = .o)

NAME	=	my_hunter

LIB_DIR	=	./lib

MY.H_DIR	=	./include

CC	=	gcc

LIB_FLAG	=	-lcsfml-audio -lcsfml-window -lcsfml-graphics -lcsfml-system

INCL_FLAG	=	-I$(MY.H_DIR)

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LIB_FLAG) $(INCL_FLAG)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: fclean all re clean
