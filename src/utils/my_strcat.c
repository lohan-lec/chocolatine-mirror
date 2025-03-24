/*
** EPITECH PROJECT, 2025
** my_strcat
** File description:
** my_strcat
*/

#include <stddef.h>
#include "utils/string_utils.h"
#include "utils/memory_utils.h"

char *my_strcat(const char *s1, const char *s2)
{
    char *result = emalloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2) + 1));
    int i = 0;
    int j = 0;

    if (result == NULL)
        return NULL;
    for (i = 0; s1[i] != '\0'; i++)
        result[i] = s1[i];
    for (j = 0; s2[j] != '\0'; j++)
        result[i + j] = s2[j];
    result[i + j] = '\0';
    return result;
}
