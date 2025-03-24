/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** output_redir
*/

#include <fcntl.h>
#include <unistd.h>
#include "core/types.h"
#include "execution/redirections.h"

int handle_output_redir(char *file, int *saved_fd, int append)
{
    int fd = 0;
    int flags = O_WRONLY | O_CREAT | O_TRUNC;

    if (append)
        flags = O_WRONLY | O_CREAT | O_APPEND;
    *saved_fd = dup(STDOUT_FILENO);
    fd = open(file, flags, 0644);
    if (fd == -1)
        return -1;
    dup2(fd, STDOUT_FILENO);
    close(fd);
    return 0;
}
