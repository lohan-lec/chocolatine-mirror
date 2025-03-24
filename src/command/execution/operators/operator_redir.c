/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** operator_redir
*/

#include <unistd.h>
#include "core/types.h"
#include "execution/execution.h"
#include "execution/redirections.h"
#include "utils/memory_utils.h"

void execute_redir(node_t *node, shell_t *shell)
{
    int saved_in = -1;
    int saved_out = -1;
    int status = 0;

    status = setup_redirection(node, &saved_in, &saved_out);
    if (status == -1) {
        my_eputstr("Redirection failed.\n");
        shell->exit_status = 84;
        return;
    }
    execute_bintree(node->left, shell);
    restore_fd(saved_in, STDIN_FILENO);
    restore_fd(saved_out, STDOUT_FILENO);
}
