/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** command argument collection
*/

#include <stdio.h>
#include <stdbool.h>
#include "core/minishell.h"
#include "parser/lexer.h"
#include "parser/binarytree.h"
#include "utils/memory_utils.h"
#include "utils/string_utils.h"

static char **collect_command_args(token_t **tokens, int *count)
{
    token_t *current = *tokens;
    int arg_count = 0;
    char **args = NULL;

    while (current && current->type == TOKEN_CMD) {
        arg_count++;
        current = current->next;
    }
    if (arg_count == 0)
        return NULL;
    args = emalloc(sizeof(char *) * (arg_count + 1));
    current = *tokens;
    for (int i = 0; i < arg_count; i++) {
        args[i] = my_strdup(current->value);
        current = current->next;
    }
    args[arg_count] = NULL;
    *tokens = current;
    *count = arg_count;
    return args;
}

node_t *parse_simple_command(token_t **tokens)
{
    int arg_count = 0;
    char **args = collect_command_args(tokens, &arg_count);

    if (!args)
        return NULL;
    return create_node(CMD, args, NULL);
}
