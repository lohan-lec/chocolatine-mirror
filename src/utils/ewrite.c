/*
** EPITECH PROJECT, 2025
** write with error gestion
** File description:
** ewrite
*/

#include <stdlib.h>
#include <unistd.h>

void ewrite(int fd, const char *str, int size)
{
    if (write(fd, str, size) == -1)
        exit(84);
}
