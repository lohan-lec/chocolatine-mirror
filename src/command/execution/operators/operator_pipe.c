/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** operator_pipe
*/

#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "core/types.h"
#include "execution/execution.h"
#include "utils/memory_utils.h"
#include "utils/string_utils.h"
#include "utils/minilib.h"

static int setup_pipe(int pipefd[2], shell_t *shell)
{
    if (pipe(pipefd) == -1) {
        my_eputstr("Can't make pipe.\n");
        shell->exit_status = 84;
        return -1;
    }
    return 0;
}

static void handle_left_pipe(int pipefd[2], node_t *node, shell_t *shell)
{
    close(pipefd[0]);
    dup2(pipefd[1], STDOUT_FILENO);
    close(pipefd[1]);
    execute_bintree(node->left, shell);
    exit(shell->exit_status);
}

static void handle_right_pipe(int pipefd[2], node_t *node, shell_t *shell)
{
    close(pipefd[1]);
    dup2(pipefd[0], STDIN_FILENO);
    close(pipefd[0]);
    execute_bintree(node->right, shell);
    exit(shell->exit_status);
}

static void handle_parent_wait(pid_t pid1, pid_t pid2, shell_t *shell)
{
    int status = 0;

    waitpid(pid1, &status, 0);
    waitpid(pid2, &status, 0);
    if (WIFEXITED(status))
        shell->exit_status = WEXITSTATUS(status);
    else if (WIFSIGNALED(status))
        shell->exit_status = 128 + WTERMSIG(status);
    else
        shell->exit_status = 0;
}

static void execute_right_side(int pipefd[2], node_t *node, pid_t pid1,
    shell_t *shell)
{
    int saved_stdin = 0;
    pid_t pid2 = -1;

    if (is_builtin(node->right)) {
        saved_stdin = dup(STDIN_FILENO);
        close(pipefd[1]);
        dup2(pipefd[0], STDIN_FILENO);
        close(pipefd[0]);
        execute_bintree(node->right, shell);
        dup2(saved_stdin, STDIN_FILENO);
        close(saved_stdin);
        waitpid(pid1, NULL, 0);
    } else {
        pid2 = fork();
        if (pid2 == 0)
            handle_right_pipe(pipefd, node, shell);
        close(pipefd[0]);
        close(pipefd[1]);
        handle_parent_wait(pid1, pid2, shell);
    }
}

void execute_pipe(node_t *node, shell_t *shell)
{
    int pipefd[2] = {0, 0};
    pid_t pid1 = -1;

    if (setup_pipe(pipefd, shell) == -1)
        return;
    pid1 = fork();
    if (pid1 == 0)
        handle_left_pipe(pipefd, node, shell);
    execute_right_side(pipefd, node, pid1, shell);
}
