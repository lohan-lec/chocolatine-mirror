/*
** EPITECH PROJECT, 2025
** my_getnbr
** File description:
** my_getnbr
*/

#include <stdio.h>
#include <stdlib.h>
#include "execution/builtins.h"
#include "utils/memory_utils.h"

static int handle_sign(char const **str)
{
    int sign = 1;

    if (**str == '-') {
        sign = -1;
        (*str)++;
    }
    return sign;
}

int my_getnbr_mysh(char const *str, int *error)
{
    int sign = handle_sign(&str);
    int result = 0;

    *error = EXIT_BADLY_FORMED;
    if (*str < '0' || *str > '9') {
        ewrite(2, "exit: Expression Syntax.\n", 26);
        return result;
    }
    while (*str) {
        if (*str < '0' || *str > '9') {
            ewrite(2, "exit: Badly formed number.\n", 27);
            return result;
        }
        result = result * 10 + (*str - '0');
        str++;
    }
    *error = EXIT_WITH_SPEC;
    return result * sign;
}
