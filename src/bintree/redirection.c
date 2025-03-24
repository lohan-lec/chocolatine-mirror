/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** redirection handling
*/

#include <stdio.h>
#include <stdbool.h>
#include "core/minishell.h"
#include "parser/lexer.h"
#include "parser/binarytree.h"
#include "utils/memory_utils.h"
#include "utils/string_utils.h"

int has_redirection_conflict(node_t *node, token_type_t token_type)
{
    if (!node)
        return 0;
    if (is_output_redirection((token_type_t)node->type) &&
            is_output_redirection(token_type))
        return 1;
    if (has_redirection_conflict(node->left, token_type))
        return 1;
    if (has_redirection_conflict(node->right, token_type))
        return 1;
    return 0;
}

static node_t *create_redirection_node(
    token_t **tokens, token_type_t token_type,
    node_t *left, bool *parser_error)
{
    node_t *redir = NULL;

    if (has_redirection_conflict(left, token_type)) {
        ewrite(2, "Ambiguous output redirect.\n", 26);
        cleanup_tree(left);
        *parser_error = true;
        return NULL;
    }
    *tokens = (*tokens)->next;
    if (!*tokens || (*tokens)->type != TOKEN_CMD) {
        ewrite(2, "Missing name for redirect.\n", 27);
        cleanup_tree(left);
        *parser_error = true;
        return NULL;
    }
    redir = create_node((type_t)token_type, NULL, my_strdup((*tokens)->value));
    redir->left = left;
    *tokens = (*tokens)->next;
    return redir;
}

node_t *parse_redirection(token_t **tokens, bool *parser_error)
{
    node_t *redir = NULL;
    node_t *left = parse_simple_command(tokens);

    if (!left && *tokens && is_redirection_token((*tokens)->type)) {
        *parser_error = true;
        ewrite(2, "Invalid null command.\n", 22);
        return NULL;
    }
    if (!left)
        return NULL;
    while (*tokens && is_redirection_token((*tokens)->type)) {
        redir = create_redirection_node(
            tokens, (*tokens)->type, left, parser_error);
        if (!redir)
            return NULL;
        left = redir;
    }
    return left;
}
