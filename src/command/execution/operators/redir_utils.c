/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** redir_utils
*/

#include <unistd.h>
#include "core/types.h"
#include "execution/redirections.h"

void restore_fd(int saved_fd, int fd)
{
    if (saved_fd != -1) {
        dup2(saved_fd, fd);
        close(saved_fd);
    }
}

int setup_redirection(node_t *node, int *saved_in, int *saved_out)
{
    int status = 0;

    switch (node->type) {
        case REDIR_IN:
            status = handle_input_redir(node->file, saved_in);
            break;
        case REDIR_OUT:
            status = handle_output_redir(node->file, saved_out, 0);
            break;
        case REDIR_OUT_APPEND:
            status = handle_output_redir(node->file, saved_out, 1);
            break;
        case HEREDOC:
            status = handle_heredoc(node->file, saved_in);
            break;
        default:
            break;
    }
    return status;
}
