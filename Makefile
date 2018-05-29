##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## a_makefile_for_projetcs
##

CC	=	gcc

RM	=	rm -rf

CFLAGS	+=	-Wall -Wextra

CPPFLAGS	+=	-I./include

NAME	=	my_hunter

SRCS	=	srcs/main.c


OBJS	=	$(SRCS:.c=.o)

ifeq ($(shell cat /etc/*-release | grep "Fedora"), )
LIB	=	-L./lib -lmy -lcsfml-audio -lcsfml-window -lcsfml-system -lcsfml-graphics
else
LIB	=	-L./lib -lmy -lc_graph_prog
endif

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./lib/my
	$(CC) $(OBJS) -o $(NAME) $(LIB)

clean:
	$(RM) $(OBJS)
	make -C ./lib/my clean

fclean: clean
	$(RM) $(NAME)
	$(RM) lib/*.a
	make -C ./lib/my fclean

re: fclean all

.PHONY: all clean fclean re
