/*
** EPITECH PROJECT, 2025
** exec errors
** File description:
** execution_errors
*/

#include "core/signals.h"
#include "utils/memory_utils.h"
#include <errno.h>

static const signal_t errors[] = {
    {E2BIG, "Argument list too long.\n"},
    {EACCES, ": Permission denied.\n"},
    {EAGAIN, "Resource temporarily unavailable.\n"},
    {EFAULT, "Bad address.\n"},
    {EINVAL, "Invalid argument.\n"},
    {EIO, "Input/output error.\n"},
    {EISDIR, ": Is a directory.\n"},
    {ELIBBAD, "Accessing a corrupted shared library.\n"},
    {ELOOP, "Too many levels of symbolic links.\n"},
    {EMFILE, "Too many open files.\n"},
    {ENAMETOOLONG, "File name too long.\n"},
    {ENFILE, "Too many open files in system.\n"},
    {ENOENT, ": Command not found.\n"},
    {ENOEXEC, ": Exec format error. Binary file not executable.\n"},
    {ENOMEM, "Not enough memory.\n"},
    {ENOTDIR, ": Not a directory.\n"},
    {EPERM, ": Operation not permitted.\n"},
    {ETXTBSY, "Text file busy.\n"},
    {-1, NULL}
};

void check_perror_execve(int err, char *command)
{
    int i = 0;

    while (errors[i].mess) {
        if (err != errors[i].signal) {
            i++;
            continue;
        }
        if (errors[i].mess[0] == ':')
            my_eputstr(command);
        my_eputstr(errors[i].mess);
        return;
    }
}
