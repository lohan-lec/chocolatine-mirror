/*
** EPITECH PROJECT, 2025
** my_putstr
** File description:
** my_eputstr
*/

#include <unistd.h>
#include <stdlib.h>
#include "utils/minilib.h"

void my_eputstr(char *str)
{
    if (write(2, str, my_strlen(str)) == -1)
        exit(84);
}
