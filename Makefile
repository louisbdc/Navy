##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## my_hunter
##

SRC	=	$(shell find -name '*.c')

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

CFLAGS	=	-Wall -Wextra -I include -g3

LDFLAGS	=	-lcsfml-system -lcsfml-graphics -lcsfml-audio -lcsfml-window

NAME	=	my_runner

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)
	@rm -f $(shell find -name '*.o')

clean:
	@rm -f $(shell find -name '*~')
	@rm -f $(shell find -name '*.o')
	@rm -f vgcore.*

fclean:	clean
	@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re