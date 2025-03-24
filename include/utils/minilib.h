/*
** EPITECH PROJECT, 2025
** minilib (only for shell)
** File description:
** minilib
*/

#ifndef MINILIB_H_
    #define MINILIB_H_
    #include <sys/types.h>
    #include "core/types.h"

int my_strncmp(char const *s1, char const *s2, int n);
char *my_strcat(const char *s1, const char *s2);
int my_strlen(char const *str);
int my_strcmp(const char *s1, const char *s2);
char *my_strdup(const char *str);
char *my_strncpy(char *dest, const char *src, int n);
char **my_str_to_word_array(char const *str, char sep);
int my_strarraylen(char **array);

void *emalloc(size_t size);
void ewrite(int fd, const char *str, int size);
void my_eputstr(char *str);
int my_getnbr_mysh(char const *str, int *error);

void my_setenv(shell_t *shell, char *var, char *value);
void my_unsetenv(shell_t *shell, const char *name);
char *my_getenv(char **env, char *name);

int is_builtin(node_t *node);

#endif /* MINILIB_H_ */
