/*
** EPITECH PROJECT, 2025
** unsets env
** File description:
** unsetenv
*/

#include "core/minishell.h"
#include "utils/memory_utils.h"

int unsetenv_builtin(node_t *node, shell_t *shell)
{
    if (!node->args[1]) {
        ewrite(2, "unsetenv: Too few arguments.\n", 29);
        shell->exit_status = 1;
        return 1;
    }
    for (int i = 1; node->args[i]; i++)
        my_unsetenv(shell, node->args[i]);
    return 1;
}
