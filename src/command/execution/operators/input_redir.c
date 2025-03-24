/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** input_redir
*/

#include <fcntl.h>
#include <unistd.h>
#include "core/types.h"
#include "execution/redirections.h"

int handle_input_redir(char *file, int *saved_fd)
{
    int fd = 0;

    *saved_fd = dup(STDIN_FILENO);
    fd = open(file, O_RDONLY);
    if (fd == -1)
        return -1;
    dup2(fd, STDIN_FILENO);
    close(fd);
    return 0;
}
