/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** Builtin commands
*/

#ifndef BUILTINS_H_
    #define BUILTINS_H_
    #include "core/types.h"

enum exit_e {
    EXIT_NO_SPEC,
    EXIT_WITH_SPEC,
    EXIT_BADLY_FORMED
};

int builtins(node_t *node, shell_t *shell);

int exit_builtin(node_t *node, shell_t *shell);
int cd_builtin(node_t *node, shell_t *shell);
int env_builtin(node_t *node, shell_t *shell);
int setenv_builtin(node_t *node, shell_t *shell);
int unsetenv_builtin(node_t *node, shell_t *shell);

int verif_exist(char *oldpwd, char *home, shell_t *shell);
void cd_home(shell_t *shell);
void cd_not_found(char *path, shell_t *shell);

int var_name_checker(char *var_name);
int my_getnbr_mysh(char const *str, int *error);

#endif /* !BUILTINS_H_ */
