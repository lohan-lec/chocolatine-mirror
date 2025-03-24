/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** Redirections handling
*/

#ifndef REDIRECTIONS_H_
    #define REDIRECTIONS_H_
    #include "core/types.h"

void restore_fd(int saved_fd, int fd);

int handle_input_redir(char *file, int *saved_fd);
int read_heredoc_content(int write_fd, char *delimiter);
int handle_heredoc(char *delimiter, int *saved_fd);

int handle_output_redir(char *file, int *saved_fd, int append);

int setup_redirection(node_t *node, int *saved_in, int *saved_out);

#endif /* !REDIRECTIONS_H_ */
