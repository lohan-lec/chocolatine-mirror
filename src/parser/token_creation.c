/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** Token creation and management
*/

#include <stdlib.h>
#include <string.h>
#include "parser/lexer.h"
#include "utils/minilib.h"
#include "utils/memory_utils.h"

static int is_whitespace(char c)
{
    return (c == ' ' || c == '\t');
}

char *lexer_get_word(const char *input, int *pos)
{
    int start = *pos;
    int len = 0;
    char *word = NULL;

    while (input[*pos] && !is_whitespace(input[*pos]) &&
        !is_operator_char(input[*pos])) {
        (*pos)++;
        len++;
    }
    word = emalloc(len + 1);
    my_strncpy(word, input + start, len);
    word[len] = '\0';
    return word;
}

token_t *lexer_create_token(token_type_t type, const char *value, int len)
{
    token_t *token = emalloc(sizeof(token_t));

    token->type = type;
    if (len > 0) {
        token->value = emalloc(len + 1);
        my_strncpy(token->value, value, len);
        token->value[len] = '\0';
    } else {
        token->value = NULL;
    }
    token->next = NULL;
    return token;
}

void lexer_free_tokens(token_t *tokens)
{
    token_t *current = tokens;
    token_t *next = NULL;

    while (current) {
        next = current->next;
        if (current->value)
            free(current->value);
        free(current);
        current = next;
    }
}
