/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** Command execution functions
*/

#ifndef EXECUTION_H_
    #define EXECUTION_H_
    #include "core/types.h"

typedef void (*executor_func_t)(node_t *node, shell_t *shell);

typedef struct executor_s {
    type_t type;
    executor_func_t execute;
} executor_t;

void execute_bintree(node_t *node, shell_t *shell);
void execute_command(node_t *node, shell_t *shell);
void execute_pipe(node_t *node, shell_t *shell);
void execute_sequence(node_t *node, shell_t *shell);
void execute_redir(node_t *node, shell_t *shell);

char *get_fullpath(char *command, char **env);
char *concat_path(char *path, char *command);
void cleanup_path_array(char **path_array);
char *try_path_locations(char **path_array, char *command);

int fork_and_exec(char *full_path, char **args, shell_t *shell);

#endif /* !EXECUTION_H_ */
