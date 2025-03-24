/*
** EPITECH PROJECT, 2025
** retrieve the current working directory
** File description:
** cwd
*/

#include <unistd.h>
#include <stdlib.h>
#include "utils/string_utils.h"
#include "core/minishell.h"

char *retrieve_cwd(shell_t *shell)
{
    char *cwd = getcwd(NULL, 0);
    char *new_cwd = NULL;
    char *home = my_getenv(shell->env, "HOME");

    if (cwd == NULL)
        return "";
    if (home == NULL || my_strncmp(cwd, home, my_strlen(home)) == 0) {
        new_cwd = my_strcat("~", cwd);
        free(cwd);
        return new_cwd;
    }
    return cwd;
}
