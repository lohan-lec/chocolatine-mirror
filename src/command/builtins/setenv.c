/*
** EPITECH PROJECT, 2025
** setenv builtin
** File description:
** setenv
*/

#include <unistd.h>
#include "execution/builtins.h"
#include "utils/string_utils.h"
#include "utils/memory_utils.h"
#include "utils/minilib.h"

int var_name_checker(char *var_name)
{
    if ((var_name[0] < 'A' || var_name[0] > 'Z') &&
        (var_name[0] < 'a' || var_name[0] > 'z') &&
        var_name[0] != '_') {
        my_eputstr("setenv: Variable name must begin with a letter.\n");
        return 1;
    }
    for (int i = 1; var_name[i] != '\0'; i++) {
        if ((var_name[i] < 'A' || var_name[i] > 'Z') &&
            (var_name[i] < 'a' || var_name[i] > 'z') &&
            (var_name[i] < '0' || var_name[i] > '9') &&
            var_name[i] != '_') {
            my_eputstr("setenv: Variable name must contain");
            my_eputstr(" alphanumeric characters.\n");
            return 1;
        }
    }
    return 0;
}

int setenv_builtin(node_t *node, shell_t *shell)
{
    if (!node->args[1]) {
        env_builtin(node, shell);
        return 1;
    }
    if (node->args[2] && node->args[3] != NULL) {
        my_eputstr("setenv: Too many arguments.\n");
        shell->exit_status = 1;
        return 1;
    }
    if (var_name_checker(node->args[1]) == 1) {
        shell->exit_status = 1;
        return 1;
    }
    if (node->args[2] == NULL)
        my_setenv(shell, node->args[1], "");
    else
        my_setenv(shell, node->args[1], node->args[2]);
    return 1;
}
