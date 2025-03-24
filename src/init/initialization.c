/*
** EPITECH PROJECT, 2025
** init the shell
** File description:
** initialization
*/

#include <stddef.h>
#include "core/minishell.h"
#include "core/types.h"

void initialize_shell(shell_t *shell)
{
    shell->hostname = get_hostname();
    shell->cwd = retrieve_cwd(shell);
    shell->exit_status = 0;
    shell->exit_requested = 0;
    if (shell->cwd == NULL)
        shell->cwd = "";
}
