/*
** EPITECH PROJECT, 2025
** creates a word array, thanks to a separator
** File description:
** my_str_to_word_array
*/

#include <stddef.h>
#include <stdlib.h>
#include "utils/string_utils.h"
#include "utils/memory_utils.h"

static int is_separator(char c, char sep)
{
    if (sep == ' ')
        return (c == ' ' || c == '\t');
    return (c == sep);
}

int skip_separators(char const *str, int i, char sep)
{
    while (is_separator(str[i], sep) && str[i] != '\0')
        i++;
    return i;
}

void copy_word(char *dest, char const *src, int *h, int k)
{
    int j = 0;

    while (*h < k) {
        dest[j] = src[*h];
        j++;
        (*h)++;
    }
    dest[j] = '\0';
}

int str_stop_at_separator(char const *str, int n, char sep)
{
    while (str[n] != '\0' && !is_separator(str[n], sep))
        n++;
    return n;
}

int count_words(char const *str, char sep)
{
    int wordcounter = 0;
    int i = 0;
    int in_word = 0;

    while (str[i] != '\0') {
        if (is_separator(str[i], sep)) {
            in_word = 0;
            i++;
            continue;
        }
        if (!in_word) {
            in_word = 1;
            wordcounter++;
        }
        i++;
    }
    return wordcounter;
}

char **my_str_to_word_array(char const *str, char sep)
{
    int size = my_strlen(str);
    char **dest = malloc(sizeof(char *) * (count_words(str, sep) + 1));
    int a = 0;
    int k = 0;
    int h = 0;

    while (k < size) {
        k = skip_separators(str, k, sep);
        h = k;
        k = str_stop_at_separator(str, k, sep);
        if (h != k) {
            dest[a] = malloc(sizeof(char) * (k - h + 1));
            copy_word(dest[a], str, &h, k);
            a++;
        }
    }
    dest[a] = NULL;
    return dest;
}
