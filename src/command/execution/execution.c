/*
** EPITECH PROJECT, 2025
** finds if a command exists and execute it
** File description:
** execution
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/types.h>

#include "core/minishell.h"
#include "execution/execution.h"
#include "execution/builtins.h"
#include "core/signals.h"

static const executor_t executors[] = {
    {CMD, execute_command},
    {PIPE, execute_pipe},
    {SEQ, execute_sequence},
    {REDIR_IN, execute_redir},
    {REDIR_OUT, execute_redir},
    {REDIR_OUT_APPEND, execute_redir},
    {HEREDOC, execute_redir}
};

int fork_and_exec(char *full_path, char **args, shell_t *shell)
{
    int pid = fork();
    int status = 0;

    if (pid == 0) {
        if (execve(full_path, args, shell->env) == -1) {
            check_perror_execve(errno, args[0]);
            free(full_path);
            cleanup(shell, 1);
            return 1;
        }
    } else
        waitpid(pid, &status, 0);
    if (WIFSIGNALED(status))
        return handle_signals(status);
    else if (WIFEXITED(status))
        return WEXITSTATUS(status);
    return 0;
}

void execute_command(node_t *node, shell_t *shell)
{
    char *full_path = NULL;

    if (builtins(node, shell))
        return;
    full_path = get_fullpath(node->args[0], shell->env);
    if (full_path == NULL) {
        shell->exit_status = 1;
        return;
    }
    shell->exit_status = fork_and_exec(full_path, node->args, shell);
    free(full_path);
}

void execute_sequence(node_t *node, shell_t *shell)
{
    int prev_status = shell->exit_status;

    execute_bintree(node->left, shell);
    if (!shell->exit_requested)
        execute_bintree(node->right, shell);
    if (!shell->exit_requested)
        shell->exit_status = prev_status;
}

void execute_bintree(node_t *node, shell_t *shell)
{
    if (!node)
        return;
    for (size_t i = 0; i < sizeof(executors) / sizeof(executors[0]); i++) {
        if (node->type == executors[i].type) {
            executors[i].execute(node, shell);
            return;
        }
    }
}
