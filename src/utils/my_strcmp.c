/*
** EPITECH PROJECT, 2025
** my strcomp
** File description:
** my_strcmp
*/

int my_strcmp(const char *s1, const char *s2)
{
    int i = 0;

    for (i = 0; s1[i] && s2[i] && s1[i] == s2[i]; i++);
    return (s1[i] - s2[i]);
}
