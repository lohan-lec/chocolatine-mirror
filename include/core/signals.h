/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** Signal handling
*/

#ifndef SIGNALS_H_
    #define SIGNALS_H_
    #include "core/types.h"

int handle_signals(int status);
void check_for_core_dump(int status);
void check_perror_execve(int err, char *command);

#endif /* !SIGNALS_H_ */
