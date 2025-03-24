##
## EPITECH PROJECT, 2025
## Stumper
## File description:
## Makefile
##

CC = gcc -g3
RM = rm -rf
INCLUDE_DIR = ./include
CPPFLAGS = -I $(INCLUDE_DIR)
CFLAGS = -Wall -Wextra -W
NAME = mysh
NAME2 = mysh2
SRC_DIRS = ./src
SRC = $(shell find $(SRC_DIRS) -name "*.c")
SRC_NO_MAIN = $(filter-out %main.c, $(SRC))
OBJ = $(SRC:.c=.o)

TESTS_DIR = ./tests
TESTS_SRC = test_ms.c
TESTS_OBJ = test_ms.o
TESTS_NAME = unit_tests
LDFLAGS = -lcriterion --coverage

all: $(NAME) $(NAME2)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

$(NAME2): $(OBJ)
	$(CC) $(OBJ) -o $(NAME2)

clean:
	$(RM) $(OBJ) $(TESTS_OBJ) *.gcda *.gcno

fclean: clean
	$(RM) $(NAME) $(NAME2) $(TESTS_NAME)

tests_run:
	printf "Running tests... fake for test\n"

re: fclean all
