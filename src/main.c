/*
** EPITECH PROJECT, 2025
** main file for the minishell
** File description:
** main
*/

#include "core/minishell.h"

int main(int ac, __attribute__((unused)) char **av, char **environ)
{
    if (ac != 1)
        return 84;
    mini_shell(environ);
    return 0;
}