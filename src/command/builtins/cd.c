/*
** EPITECH PROJECT, 2025
** cd builtin
** File description:
** cd
*/

#include <unistd.h>
#include <errno.h>
#include "core/minishell.h"
#include "utils/minilib.h"
#include "utils/memory_utils.h"
#include "utils/string_utils.h"

static const signal_t errors[] = {
    {EACCES, ": Permission denied.\n"},
    {ENOENT, ": No such file or directory.\n"},
    {ENOTDIR, ": Not a directory.\n"},
    {ENAMETOOLONG, ": File name too long.\n"},
    {EFAULT, ": Bad address.\n"},
    {EIO, ": Input/output error.\n"},
    {ELOOP, ": Too many levels of symbolic links.\n"},
    {ENOMEM, ": Not enough memory.\n"},
    {EPERM, ": Operation not permitted.\n"},
    {ETXTBSY, ": Text file busy.\n"},
    {-1, NULL}
};

int verif_exist(char *oldpwd, char *home, shell_t *shell)
{
    if (!oldpwd) {
        ewrite(2, "Variable OLDPWD is not set.", 27);
        shell->exit_status = 1;
        return 1;
    }
    if (!home) {
        ewrite(2, "cd: No home directory.\n", 23);
        shell->exit_status = 1;
        return 1;
    }
    return 0;
}

void cd_home(shell_t *shell)
{
    char *home = my_getenv(shell->env, "HOME");
    char *oldpwd = my_getenv(shell->env, "OLDPWD");

    if (verif_exist(oldpwd, home, shell))
        return;
    if (chdir(home) == -1) {
        ewrite(2, home, my_strlen(home));
        ewrite(2, ": No such file or directory.\n", 29);
        shell->exit_status = 1;
        return;
    }
    my_setenv(shell, "OLDPWD", oldpwd);
    my_setenv(shell, "PWD", home);
}

void cd_not_found(char *path, shell_t *shell)
{
    my_eputstr(path);
    for (int i = 0; errors[i].mess; i++) {
        if (errno == errors[i].signal) {
            my_eputstr(errors[i].mess);
            break;
        }
    }
    shell->exit_status = 1;
}

static void cd_with_arg(shell_t *shell, node_t *node)
{
    char *current_dir = NULL;
    char *cwd = NULL;

    if (chdir(node->args[1]) == -1)
        cd_not_found(node->args[1], shell);
    cwd = getcwd(NULL, 0);
    current_dir = my_getenv(shell->env, "PWD");
    my_setenv(shell, "OLDPWD", current_dir);
    my_setenv(shell, "PWD", cwd);
    free(cwd);
}

static void cd_previous(shell_t *shell)
{
    char *oldpwd = my_strdup(my_getenv(shell->env, "OLDPWD"));
    char *pwd = my_strdup(my_getenv(shell->env, "PWD"));

    if (!oldpwd) {
        my_eputstr(": No such file or directory.\n");
        shell->exit_status = 1;
        return;
    }
    if (chdir(oldpwd) == -1) {
        cd_not_found(oldpwd, shell);
        return;
    }
    my_setenv(shell, "OLDPWD", pwd);
    my_setenv(shell, "PWD", oldpwd);
    free(oldpwd);
    free(pwd);
}

int cd_builtin(node_t *node, shell_t *shell)
{
    if (my_strarraylen(node->args) > 2) {
        my_eputstr("cd: Too many arguments.\n");
        shell->exit_status = 1;
        return 1;
    }
    if (node->args[1] == NULL || !my_strcmp(node->args[1], "~")) {
        cd_home(shell);
    } else {
        if (!my_strcmp(node->args[1], "-"))
            cd_previous(shell);
        else
            cd_with_arg(shell, node);
    }
    free(shell->cwd);
    shell->cwd = retrieve_cwd(shell);
    return 1;
}
