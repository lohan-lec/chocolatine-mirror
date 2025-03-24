/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** Binary tree structure and functions
*/

#ifndef BINARYTREE_H_
    #define BINARYTREE_H_

    #include <stdbool.h>
    #include "core/types.h"
    #include "parser/lexer.h"

node_t *create_binary_tree(char *command, shell_t *shell);
node_t *create_node(type_t type, char **args, char *filename);
type_t get_redir_type(char *str);

node_t *parse_simple_command(token_t **tokens);

node_t *parse_redirection(token_t **tokens, bool *parser_error);
int has_redirection_conflict(node_t *node, token_type_t token_type);

node_t *parse_pipe(token_t **tokens, bool *parser_error);

node_t *parse_sequence(token_t **tokens, bool *parser_error);

#endif /* !BINARYTREE_H_ */
