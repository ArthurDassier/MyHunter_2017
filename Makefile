##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## a_makefile_for_projetcs
##

CC	=	gcc

RM	=	rm -rf

CFLAGS	+=	-Wall -Wextra

CFLAGS	+=	-I./include

NAME	=	my_hunter

SRCS	=	srcs/main.c	\
		srcs/play.c	\
		srcs/init.c	\
		srcs/oaso.c	\
		srcs/utils.c	\

OBJS	=	$(SRCS:.c=.o)

ifeq ($(shell cat /etc/*-release | grep "Fedora"), )
LIB	=	-lcsfml-window -lcsfml-graphics -lcsfml-audio -lcsfml-system -lmy -L./lib -lmy
else
LIB	=	-lc_graph_prog -L./lib -lmy
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
