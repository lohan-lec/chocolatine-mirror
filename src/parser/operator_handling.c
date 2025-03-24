/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** Operator handling functions for lexer
*/

#include <stdlib.h>
#include "parser/lexer.h"
#include "utils/minilib.h"
#include "utils/memory_utils.h"

const operator_type_t operator_types[] = {
    {";", TOKEN_SEQ},
    {"|", TOKEN_PIPE},
    {"<", TOKEN_REDIR_IN},
    {">", TOKEN_REDIR_OUT},
    {">>", TOKEN_REDIR_APPEND},
    {"<<", TOKEN_HEREDOC},
    {NULL, TOKEN_CMD}
};

int is_operator_char(char c)
{
    return (c == ';' || c == '|' || c == '<' || c == '>');
}

int is_second_char_operator(char c)
{
    return (c == '>' || c == '<');
}

token_type_t get_operator_type(const char *op)
{
    for (int i = 0; operator_types[i].op != NULL; i++) {
        if (my_strcmp(op, operator_types[i].op) == 0)
            return operator_types[i].type;
    }
    return TOKEN_CMD;
}

char *lexer_get_operator(const char *input, int *pos)
{
    char *op = NULL;

    if (input[*pos + 1] && is_second_char_operator(input[*pos + 1])) {
        op = emalloc(3);
        op[0] = input[*pos];
        op[1] = input[*pos + 1];
        op[2] = '\0';
        *pos += 2;
    } else {
        op = emalloc(2);
        op[0] = input[*pos];
        op[1] = '\0';
        (*pos)++;
    }
    return op;
}
