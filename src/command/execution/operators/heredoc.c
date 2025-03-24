/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** heredoc
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "utils/string_utils.h"
#include "execution/redirections.h"

int read_heredoc_content(int write_fd, char *delimiter)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read = 0;

    read = getline(&line, &len, stdin);
    while (read != -1) {
        if (line[read - 1] == '\n')
            line[read - 1] = '\0';
        if (!my_strcmp(line, delimiter))
            break;
        write(write_fd, line, my_strlen(line));
        write(write_fd, "\n", 1);
        read = getline(&line, &len, stdin);
    }
    free(line);
    return 0;
}

int handle_heredoc(char *delimiter, int *saved_fd)
{
    int pipefd[2];

    if (pipe(pipefd) == -1)
        return -1;
    *saved_fd = dup(STDIN_FILENO);
    read_heredoc_content(pipefd[1], delimiter);
    close(pipefd[1]);
    dup2(pipefd[0], STDIN_FILENO);
    close(pipefd[0]);
    return 0;
}
