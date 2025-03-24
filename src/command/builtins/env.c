/*
** EPITECH PROJECT, 2025
** setenv
** File description:
** setenv
*/

#include <unistd.h>
#include "core/types.h"
#include "utils/string_utils.h"

int env_builtin(node_t *node, shell_t *shell)
{
    if (node->args[1] != NULL) {
        write(2, "env: '", 6);
        write(2, node->args[1], my_strlen(node->args[1]));
        write(2, "': No such file or directory\n", 28);
        shell->exit_status = 1;
        return 1;
    }
    for (int i = 0; shell->env[i] != NULL; i++) {
        write(1, shell->env[i], my_strlen(shell->env[i]));
        write(1, "\n", 1);
    }
    return 1;
}
