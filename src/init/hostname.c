/*
** EPITECH PROJECT, 2025
** retrieves the host name
** File description:
** hostname
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "utils/string_utils.h"
#include "core/minishell.h"

char *get_hostname(void)
{
    int fd = open("/etc/hostname", O_RDONLY);
    char *hostname = NULL;
    ssize_t read_len;
    char buffer[MAX_HOSTNAME_SIZE];

    if (fd == -1)
        return "";
    read_len = read(fd, buffer, sizeof(buffer) - 1);
    if (read_len == -1) {
        close(fd);
        return "";
    }
    buffer[read_len] = '\0';
    close(fd);
    hostname = my_strdup(buffer);
    hostname[my_strlen(hostname) - 1] = '\0';
    return hostname;
}
