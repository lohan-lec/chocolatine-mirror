/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** Lexer for shell command parsing
*/

#ifndef LEXER_H_
    #define LEXER_H_
    #include "core/types.h"

typedef enum token_type_e {
    TOKEN_CMD = CMD,
    TOKEN_PIPE = PIPE,
    TOKEN_SEQ = SEQ,
    TOKEN_REDIR_IN = REDIR_IN,
    TOKEN_REDIR_OUT = REDIR_OUT,
    TOKEN_REDIR_APPEND = REDIR_OUT_APPEND,
    TOKEN_HEREDOC = HEREDOC,
    TOKEN_EOF
} token_type_t;

typedef struct token_s {
    token_type_t type;
    char *value;
    struct token_s *next;
} token_t;

typedef struct operator_type_s {
    const char *op;
    token_type_t type;
} operator_type_t;

extern const operator_type_t operator_types[];

token_t *lexer_tokenize(const char *input);
void lexer_free_tokens(token_t *tokens);
token_t *lexer_create_token(token_type_t type, const char *value, int len);
char *lexer_get_operator(const char *input, int *pos);
char *lexer_get_word(const char *input, int *pos);

int is_operator_char(char c);
token_type_t get_operator_type(const char *op);

int is_redirection_token(token_type_t type);
int is_output_redirection(token_type_t type);
int is_input_redirection(token_type_t type);
int is_valid_command_start(token_type_t type);

#endif /* !LEXER_H_ */
