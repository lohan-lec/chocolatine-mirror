/*
** EPITECH PROJECT, 2024
** strlen
** File description:
** my_strlen
*/

int my_strlen(char const *str)
{
    int n = 0;

    for (; *str != '\0'; str++)
        n++;
    return n;
}
