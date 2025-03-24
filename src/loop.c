/*
** EPITECH PROJECT, 2025
** Minishell epitech project
** File description:
** loop
*/

#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include "core/minishell.h"
#include "utils/memory_utils.h"
#include "utils/string_utils.h"
#include "execution/execution.h"

void disp_prompt(shell_t *shell)
{
    char *username = my_getenv(shell->env, "USER");

    ewrite(1, "\033[1;36m", 7);
    ewrite(1, username, my_strlen(username));
    ewrite(1, "@", 1);
    ewrite(1, "\033[1;35m", 7);
    ewrite(1, shell->hostname, my_strlen(shell->hostname));
    ewrite(1, " ", 1);
    ewrite(1, "\033[1;34m", 7);
    ewrite(1, "in ", 3);
    ewrite(1, "\033[1;32m", 7);
    ewrite(1, shell->cwd, my_strlen(shell->cwd));
    ewrite(1, "\033[0m", 4);
    ewrite(1, "\n", 1);
    if (shell->exit_status != 0) {
        ewrite(1, "\033[1;31m", 7);
    } else
        ewrite(1, "\033[1;32m", 7);
    ewrite(1, " ↣ ", my_strlen(" ↣ "));
    ewrite(1, "\033[0m", 4);
}

void loop(shell_t *shell)
{
    disp_prompt(shell);
    get_input(shell);
    execute_bintree(shell->head, shell);
    cleanup_tree(shell->head);
    shell->head = NULL;
    if (shell->exit_requested)
        cleanup(shell, shell->exit_status);
}

char **copy_env(char **env)
{
    int len = my_strarraylen(env);
    char **new_env = emalloc(sizeof(char *) * (len + 1));

    for (int i = 0; i < len; i++)
        new_env[i] = my_strdup(env[i]);
    new_env[len] = NULL;
    return new_env;
}

void mini_shell(char **env)
{
    shell_t *shell = emalloc(sizeof(shell_t));

    shell->env = copy_env(env);
    initialize_shell(shell);
    if (isatty(0) == 1) {
        while (1)
            loop(shell);
    }
    while (get_input(shell)) {
        execute_bintree(shell->head, shell);
        cleanup_tree(shell->head);
        shell->head = NULL;
        if (shell->exit_requested)
            break;
        if (shell->exit_status != 0)
            break;
    }
    cleanup(shell, shell->exit_status);
}
