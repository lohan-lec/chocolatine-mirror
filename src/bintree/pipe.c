/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** pipe parsing
*/

#include <stdio.h>
#include <stdbool.h>
#include "core/minishell.h"
#include "parser/lexer.h"
#include "parser/binarytree.h"
#include "utils/memory_utils.h"
#include "utils/string_utils.h"

static int handle_pipe_invalid_sequence(
    token_t **tokens, node_t *pipe, bool *parser_error)
{
    if (!*tokens || (*tokens)->type == TOKEN_EOF) {
        *parser_error = true;
        ewrite(2, "Invalid null command.\n", 22);
        cleanup_tree(pipe);
        return 1;
    }
    if ((*tokens)->type == TOKEN_PIPE || (*tokens)->type == TOKEN_SEQ) {
        *parser_error = true;
        ewrite(2, "Invalid null command.\n", 22);
        cleanup_tree(pipe);
        return 1;
    }
    return 0;
}

static int handle_pipe_error(
    token_t **tokens, node_t *left, bool *parser_error, node_t **pipe)
{
    if (has_redirection_conflict(left, TOKEN_REDIR_OUT)) {
        ewrite(2, "Ambiguous output redirect.\n", 26);
        cleanup_tree(left);
        *parser_error = true;
        return 1;
    }
    *tokens = (*tokens)->next;
    *pipe = create_node((type_t)TOKEN_PIPE, NULL, NULL);
    (*pipe)->left = left;
    return 0;
}

node_t *parse_pipe(token_t **tokens, bool *parser_error)
{
    node_t *pipe = NULL;
    node_t *left = parse_redirection(tokens, parser_error);

    if (!left)
        return NULL;
    while (*tokens && (*tokens)->type == TOKEN_PIPE) {
        if (handle_pipe_error(tokens, left, parser_error, &pipe))
            return NULL;
        if (handle_pipe_invalid_sequence(tokens, pipe, parser_error))
            return NULL;
        pipe->right = parse_redirection(tokens, parser_error);
        if (!pipe->right) {
            cleanup_tree(pipe);
            *parser_error = true;
            return NULL;
        }
        left = pipe;
    }
    return left;
}
