/*
** EPITECH PROJECT, 2025
** mystraaraylen
** File description:
** my_strarraylen
*/

int my_strarraylen(char **array)
{
    int index = 0;

    while (array[index])
        index++;
    return index;
}
