/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** bintree main functions
*/

#include <stdio.h>
#include <stdbool.h>
#include "core/minishell.h"
#include "parser/lexer.h"
#include "parser/binarytree.h"
#include "utils/memory_utils.h"
#include "utils/string_utils.h"

static bool validate_token_type(token_t *tokens, bool *parser_error)
{
    if (tokens->type != TOKEN_CMD &&
            tokens->type != TOKEN_SEQ && tokens->type != TOKEN_EOF) {
        *parser_error = true;
        ewrite(2, "Invalid null command.\n", 22);
        return false;
    }
    return true;
}

static node_t *process_tokens(token_t *tokens, bool *parser_error)
{
    if (!validate_token_type(tokens, parser_error))
        return NULL;
    return parse_sequence(&tokens, parser_error);
}

node_t *create_binary_tree(char *command, shell_t *shell)
{
    token_t *tokens = NULL;
    node_t *head = NULL;
    bool parser_error = false;

    if (!command)
        return NULL;
    tokens = lexer_tokenize(command);
    if (!tokens)
        return NULL;
    head = process_tokens(tokens, &parser_error);
    if (parser_error && !shell->exit_status)
        shell->exit_status = 1;
    lexer_free_tokens(tokens);
    return head;
}
