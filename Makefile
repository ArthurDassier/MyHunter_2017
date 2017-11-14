##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

SRC	=	srcs/BootstrapOpenWindow.c		\

OBJ	=	$(SRC:.c = .o)

NAME	=	my_hunter
LIB_DIR	=	./lib

MY.H_DIR	=	./include

CC	=	gcc

LIB_FLAG	=	-l c_graph_prog

INCL_FLAG	=	-I$(MY.H_DIR)

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LIB_FLAG)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: fclean all re clean
