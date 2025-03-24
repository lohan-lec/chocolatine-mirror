/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** Main tokenizer function
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

static void append_token(token_t **head, token_t **current, token_t *new_token)
{
    if (!*head)
        *head = new_token;
    else
        (*current)->next = new_token;
    *current = new_token;
}

static token_t *process_token(const char *input, int *pos)
{
    token_t *new_token = NULL;
    char *word = NULL;
    char *op = NULL;

    if (is_operator_char(input[*pos])) {
        op = lexer_get_operator(input, pos);
        new_token = lexer_create_token(get_operator_type(op), op, strlen(op));
        free(op);
    } else {
        word = lexer_get_word(input, pos);
        new_token = lexer_create_token(TOKEN_CMD, word, strlen(word));
        free(word);
    }
    return new_token;
}

token_t *lexer_tokenize(const char *input)
{
    token_t *head = NULL;
    token_t *current = NULL;
    int pos = 0;

    while (input[pos]) {
        while (input[pos] && is_whitespace(input[pos]))
            pos++;
        if (!input[pos])
            break;
        append_token(&head, &current, process_token(input, &pos));
    }
    if (!head)
        head = lexer_create_token(TOKEN_EOF, NULL, 0);
    else
        current->next = lexer_create_token(TOKEN_EOF, NULL, 0);
    return head;
}
