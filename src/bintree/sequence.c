/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** sequence parsing
*/

#include <stdio.h>
#include <stdbool.h>
#include "core/minishell.h"
#include "parser/lexer.h"
#include "parser/binarytree.h"
#include "utils/memory_utils.h"
#include "utils/string_utils.h"

static int handle_seq_invalid_token(
    token_t **tokens, node_t *seq, bool *parser_error)
{
    if (is_redirection_token((*tokens)->type)) {
        *parser_error = true;
        ewrite(2, "Missing name for redirect.\n", 27);
        cleanup_tree(seq);
        return 1;
    }
    if (!is_valid_command_start(
            (*tokens)->type) && (*tokens)->type != TOKEN_SEQ) {
        *parser_error = true;
        ewrite(2, "Invalid null command.\n", 22);
        cleanup_tree(seq);
        return 1;
    }
    return 0;
}

static void skip_leading_semicolons(token_t **tokens)
{
    while (*tokens && (*tokens)->type == TOKEN_SEQ)
        *tokens = (*tokens)->next;
}

static node_t *handle_sequence_part(
    token_t **tokens, node_t *left, bool *parser_error)
{
    node_t *seq = create_node(SEQ, NULL, NULL);

    seq->left = left;
    if (!*tokens || (*tokens)->type == TOKEN_EOF)
        return seq;
    if (handle_seq_invalid_token(tokens, seq, parser_error))
        return NULL;
    seq->right = parse_pipe(tokens, parser_error);
    return seq;
}

node_t *parse_sequence(token_t **tokens, bool *parser_error)
{
    node_t *seq = NULL;
    node_t *left = NULL;

    skip_leading_semicolons(tokens);
    left = parse_pipe(tokens, parser_error);
    if (!left)
        return NULL;
    while (*tokens && (*tokens)->type == TOKEN_SEQ) {
        *tokens = (*tokens)->next;
        seq = handle_sequence_part(tokens, left, parser_error);
        if (!seq)
            return NULL;
        left = seq;
    }
    return left;
}
