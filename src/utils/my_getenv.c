/*
** EPITECH PROJECT, 2025
** get the env
** File description:
** my_getenv
*/

#include <stddef.h>
#include "utils/string_utils.h"

char *my_getenv(char **env, char *name)
{
    while (*env) {
        if (my_strncmp(*env, name, my_strlen(name)) == 0
        && (*env)[my_strlen(name)] == '=')
            return *env + my_strlen(name) + 1;
        env++;
    }
    return NULL;
}
