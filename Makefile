##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC	=	$(shell find -name '*.c')

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

CFLAGS	=	-Wall -Wextra -I includes -g3

NAME	=	navy

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS)
	@rm -f $(shell find -name '*.o')
	@rm -f $(shell find -name '*tmp')

clean:
	@rm -f $(shell find -name '*~')
	@rm -f $(shell find -name '*.o')
	@rm -f $(shell find -name '*tmp')
	@rm -f vgcore.*
	@rm -rf .idea*

fclean:	clean
	@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
