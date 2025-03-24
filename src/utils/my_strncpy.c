/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** my_strncpy
*/

char *my_strncpy(char *dest, const char *src, int n)
{
    int i = 0;

    for (i = 0; i < n && src[i] != '\0'; i++)
        dest[i] = src[i];
    for (; i < n; i++)
        dest[i] = '\0';
    return dest;
}
