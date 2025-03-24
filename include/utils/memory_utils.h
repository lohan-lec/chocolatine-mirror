/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** Memory and error utility functions
*/

#ifndef MEMORY_UTILS_H_
    #define MEMORY_UTILS_H_
    #include <stddef.h>
    #include "core/types.h"

void *emalloc(size_t size);

void ewrite(int fd, const char *str, int size);
void my_eputstr(char *str);

void cleanup_tree(node_t *node);
void cleanup_env(char **env);
void cleanup(shell_t *shell, int ret);

#endif /* !MEMORY_UTILS_H_ */
