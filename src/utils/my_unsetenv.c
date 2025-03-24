/*
** EPITECH PROJECT, 2025
** my_unsetenv
** File description:
** my_unsetenv
*/

#include <stdlib.h>
#include "core/types.h"
#include "utils/string_utils.h"

void shift_ptrs(char **env_ptr)
{
    char **current_env = env_ptr;

    while (*current_env) {
        current_env[0] = current_env[1];
        current_env++;
    }
}

void my_unsetenv(shell_t *shell, const char *name)
{
    int name_len = 0;
    char **env_ptr = NULL;

    if (!shell || !shell->env || !name)
        return;
    name_len = my_strlen(name);
    env_ptr = shell->env;
    while (*env_ptr) {
        if (!my_strncmp(*env_ptr, name, name_len)
        && (*env_ptr)[name_len] == '=') {
            free(*env_ptr);
            shift_ptrs(env_ptr);
            continue;
        }
        env_ptr++;
    }
}
