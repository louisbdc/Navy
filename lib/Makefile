##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## oui
##

SRC	=	$(wildcard *.c) \
		bases/base.c	\

OBJ	=	$(SRC:.c=.o)

LIB	=	libmy.a

name: $(OBJ)
	ar -rc $(LIB) $(OBJ)

clean:
	rm -f $(OBJ)
	rm -f *~

fclean:	clean
	rm -f $(LIB)

re:	fclean	all

all:	name
