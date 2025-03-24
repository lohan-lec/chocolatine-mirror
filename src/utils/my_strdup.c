/*
** EPITECH PROJECT, 2025
** my_strdup
** File description:
** my_strdup
*/

#include <stddef.h>
#include "utils/string_utils.h"
#include "utils/memory_utils.h"

char *my_strdup(const char *str)
{
    int len = 0;
    char *new_str = NULL;

    if (!str)
        return NULL;
    len = my_strlen(str);
    new_str = emalloc(sizeof(char) * (len + 1));
    for (int i = 0; i < len; i++)
        new_str[i] = str[i];
    new_str[len] = '\0';
    return new_str;
}
