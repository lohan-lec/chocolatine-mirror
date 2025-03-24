/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** is_builtin
*/

#include "core/minishell.h"
#include "utils/minilib.h"

int is_builtin(node_t *node)
{
    if (!node || !node->args || !node->args[0])
        return 0;
    return (my_strcmp(node->args[0], "cd") == 0 ||
            my_strcmp(node->args[0], "exit") == 0 ||
            my_strcmp(node->args[0], "setenv") == 0 ||
            my_strcmp(node->args[0], "unsetenv") == 0);
}
