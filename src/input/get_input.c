/*
** EPITECH PROJECT, 2025
** get the command entered by the user
** File description:
** get_input
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "core/types.h"
#include "parser/binarytree.h"
#include "utils/string_utils.h"

int get_input(shell_t *shell)
{
    size_t len = 0;
    ssize_t read = 0;
    char *command = NULL;

    read = getline(&command, &len, stdin);
    if (read == -1) {
        if (command)
            free(command);
        shell->head = NULL;
        return 0;
    }
    command[my_strlen(command) - 1] = '\0';
    shell->head = create_binary_tree(command, shell);
    free(command);
    return 1;
}
