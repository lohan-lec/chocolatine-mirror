/*
** EPITECH PROJECT, 2025
** my_setenv
** File description:
** my_setenv
*/

#include <stdlib.h>
#include "core/types.h"
#include "utils/string_utils.h"
#include "utils/memory_utils.h"

void add_to_env(shell_t *shell, char *new_var)
{
    int env_len = my_strarraylen(shell->env);
    char **new_env = emalloc(sizeof(char *) * (env_len + 2));
    char **old_env = shell->env;
    int i = 0;

    while (old_env[i]) {
        new_env[i] = my_strdup(old_env[i]);
        i++;
    }
    new_env[i] = new_var;
    new_env[i + 1] = NULL;
    for (i = 0; old_env[i]; i++)
        free(old_env[i]);
    free(old_env);
    shell->env = new_env;
}

void my_setenv(shell_t *shell, char *var, char *value)
{
    char *new_var = NULL;
    char *temp = NULL;
    int i = 0;

    if (!shell || !shell->env || !var || !value)
        return;
    temp = my_strcat(var, "=");
    new_var = my_strcat(temp, value);
    if (temp)
        free(temp);
    while (shell->env[i]) {
        if (my_strncmp(shell->env[i], var, my_strlen(var)) == 0 &&
            shell->env[i][my_strlen(var)] == '=') {
            free(shell->env[i]);
            shell->env[i] = new_var;
            return;
        }
        i++;
    }
    add_to_env(shell, new_var);
}
