/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** Main shell header
*/

#ifndef MINISHELL_H_
    #define MINISHELL_H_
    #define MAX_HOSTNAME_SIZE 64
    #include "core/types.h"

void initialize_shell(shell_t *shell);
char *retrieve_cwd(shell_t *shell);
char *get_hostname(void);

void mini_shell(char **env);
void loop(shell_t *shell);
void disp_prompt(shell_t *shell);
int get_input(shell_t *shell);
char **copy_env(char **env);

char *my_getenv(char **env, char *name);
void my_setenv(shell_t *shell, char *var, char *value);
void my_unsetenv(shell_t *shell, const char *name);
void add_to_env(shell_t *shell, char *new_var);
void shift_ptrs(char **env_ptr);

void execute_bintree(node_t *node, shell_t *shell);
void cleanup_tree(node_t *node);
void cleanup(shell_t *shell, int ret);

#endif /* !MINISHELL_H_ */
