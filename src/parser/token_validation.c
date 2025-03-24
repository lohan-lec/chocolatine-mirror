/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** Token validation functions
*/

#include "parser/lexer.h"
#include "core/types.h"

int is_redirection_token(token_type_t type)
{
    return (type == TOKEN_REDIR_IN ||
            type == TOKEN_REDIR_OUT ||
            type == TOKEN_REDIR_APPEND ||
            type == TOKEN_HEREDOC);
}

int is_output_redirection(token_type_t type)
{
    return (type == TOKEN_REDIR_OUT || type == TOKEN_REDIR_APPEND);
}

int is_input_redirection(token_type_t type)
{
    return (type == TOKEN_REDIR_IN || type == TOKEN_HEREDOC);
}

int is_valid_command_start(token_type_t type)
{
    return (type == TOKEN_CMD || type == TOKEN_EOF);
}
