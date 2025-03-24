/*
** EPITECH PROJECT, 2025
** looks if a command is in the builtins
** File description:
** is_command_builtin
*/

#include <unistd.h>
#include "core/minishell.h"
#include "execution/builtins.h"
#include "utils/memory_utils.h"
#include "utils/string_utils.h"

int exit_builtin(node_t *node, shell_t *shell)
{
    int return_val = 0;
    int error = EXIT_NO_SPEC;

    if (node->args[1]) {
        if (node->args[2])
            ewrite(2, "exit: Expression Syntax.\n", 26);
        return_val = my_getnbr_mysh(node->args[1], &error);
        if (error == EXIT_WITH_SPEC) {
            shell->exit_status = return_val;
            shell->exit_requested = 1;
        }
    } else {
        shell->exit_requested = 1;
    }
    return 1;
}

int builtins(node_t *node, shell_t *shell)
{
    if (my_strcmp(node->args[0], "exit") == 0)
        return exit_builtin(node, shell);
    if (my_strcmp(node->args[0], "cd") == 0)
        return cd_builtin(node, shell);
    if (my_strcmp(node->args[0], "env") == 0)
        return env_builtin(node, shell);
    if (my_strcmp(node->args[0], "setenv") == 0)
        return setenv_builtin(node, shell);
    if (my_strcmp(node->args[0], "unsetenv") == 0)
        return unsetenv_builtin(node, shell);
    return 0;
}
