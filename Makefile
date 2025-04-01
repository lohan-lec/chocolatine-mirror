##
## EPITECH PROJECT, 2025
## B-DOP-200-MPL-2-1-chocolatine-lohan.lecoq
## File description:
## Makefile
##

NAME	=	mysh
NAME2	=	mysh2

SRC	=	main.c
SRC2	=	main2.c

OBJ	=	$(SRC:.c=.o)
OBJ2	=	$(SRC2:.c=.o)

CFLAGS	=	-Wall -Wextra

all: $(NAME) $(NAME2)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

$(NAME2): $(OBJ2)
	gcc -o $(NAME2) $(OBJ2) $(CFLAGS)

clean:
	rm -f $(OBJ) $(OBJ2)

fclean: clean
	rm -f $(NAME) $(NAME2)

re: fclean all

tests_run:
	@echo "Running tests"

.PHONY: all clean fclean re tests_run
