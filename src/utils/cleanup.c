/*
** EPITECH PROJECT, 2025
** cleans the allocated ressources for mini shell
** File description:
** cleanup
*/

#include <stdlib.h>
#include "core/types.h"
#include "utils/memory_utils.h"

void cleanup_tree(node_t *node)
{
    if (!node)
        return;
    cleanup_tree(node->left);
    cleanup_tree(node->right);
    if (node->args) {
        for (int i = 0; node->args[i]; i++)
            free(node->args[i]);
        free(node->args);
    }
    if (node->file)
        free(node->file);
    free(node);
}

void cleanup_env(char **env)
{
    for (int i = 0; env[i]; i++)
        free(env[i]);
    free(env);
}

void cleanup(shell_t *shell, int ret)
{
    cleanup_tree(shell->head);
    if (shell) {
        if (shell->hostname)
            free(shell->hostname);
        if (shell->cwd)
            free(shell->cwd);
        if (shell->env)
            cleanup_env(shell->env);
        free(shell);
    }
    exit(ret);
}
