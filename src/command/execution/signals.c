/*
** EPITECH PROJECT, 2025
** handles signals
** File description:
** signals
*/

#include "core/signals.h"
#include "utils/string_utils.h"
#include <signal.h>
#include <unistd.h>
#include <wait.h>

const signal_t all_signals[] = {
    {SIGQUIT, "Quit"},
    {SIGILL, "Illegal instruction"},
    {SIGABRT, "Aborted"},
    {SIGFPE, "Floating exception"},
    {SIGSEGV, "Segmentation fault"},
    {SIGBUS, "Bus Error"},
    {SIGSYS, "Bad System Call"},
    {SIGTRAP, "Trace/Breakpoint Trap"},
    {SIGXCPU, "CPU Time Limit Exceeded"},
    {SIGXFSZ, "File Size Limit Exceeded"},
    {SIGSTOP, "Stopped"},
    {SIGTSTP, "Stopped (tty input)"},
    {SIGTTIN, "Stopped (tty input)"},
    {SIGTTOU, "Stopped (tty output)"},
    {SIGHUP, "Hangup"},
    {SIGINT, "Interrupt"},
    {SIGKILL, "Killed"},
    {SIGPIPE, "Broken Pipe"},
    {SIGALRM, "Alarm Clock"},
    {SIGTERM, "Terminated"},
    {0, NULL}
};

void check_for_core_dump(int status)
{
    if (__WCOREDUMP(status))
        write(1, " (core dumped)", 14);
    write(1, "\n", 1);
}

int handle_signals(int status)
{
    int sig = WTERMSIG(status);

    for (int i = 0; all_signals[i].mess != NULL; i++) {
        if (all_signals[i].signal == sig) {
            write(1, all_signals[i].mess, my_strlen(all_signals[i].mess));
            break;
        }
    }
    check_for_core_dump(status);
    return 128 + sig;
}
