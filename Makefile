##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## all clean fclean re
##

SRC	=	main.c

OBJ	=	$(SRC:.c=.o)

CC	= 	gcc

NAME	=	bsq

HFLAGS	=	-I./include

LFLAGS	=	-L./lib/my -lmy

all:	prepare_lib $(NAME)

prepare_lib:
	make -C lib/my

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(HFLAGS) $(LFLAGS)

clean:
	make clean -C lib/my
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
