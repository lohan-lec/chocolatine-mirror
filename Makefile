##
## EPITECH PROJECT, 2025
## B-DOP-200-MPL-2-1-chocolatine-lohan.lecoq
## File description:
## Makefile
##

NAME	=	program

SRC	=	main.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

tests_run:
	@echo "Running tests"

.PHONY: all clean fclean re tests_run
