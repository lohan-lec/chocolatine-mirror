/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** String utility functions
*/

#ifndef STRING_UTILS_H_
    #define STRING_UTILS_H_
    #include <stddef.h>

int my_strcmp(const char *s1, const char *s2);
int my_strncmp(char const *s1, char const *s2, int n);

int my_strlen(char const *str);
char *my_strcat(const char *s1, const char *s2);
char *my_strdup(const char *str);

char **my_str_to_word_array(char const *str, char sep);
int my_strarraylen(char **array);

#endif /* !STRING_UTILS_H_ */
