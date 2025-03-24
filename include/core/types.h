/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** Common type definitions
*/

#ifndef TYPES_H_
    #define TYPES_H_
    #include <stdlib.h>

typedef enum type_e {
    CMD,
    PIPE,
    SEQ,
    REDIR_IN,
    REDIR_OUT,
    REDIR_OUT_APPEND,
    HEREDOC
} type_t;

typedef struct node_s {
    type_t type;
    char **args;
    char *file;
    struct node_s *left;
    struct node_s *right;
} node_t;

typedef struct signal_s {
    int signal;
    char *mess;
} signal_t;

typedef struct shell_s {
    char *hostname;
    char *cwd;
    node_t *head;
    int exit_status;
    char **env;
    int exit_requested;
} shell_t;

#endif /* !TYPES_H_ */
