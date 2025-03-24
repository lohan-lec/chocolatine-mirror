/*
** EPITECH PROJECT, 2025
** creates a node for the bintree
** File description:
** node_creation
*/

#include <stdio.h>
#include "parser/binarytree.h"
#include "utils/memory_utils.h"
#include "core/types.h"

node_t *create_node(type_t type, char **args, char *filename)
{
    node_t *node = emalloc(sizeof(node_t));

    node->type = type;
    node->args = args;
    node->file = filename;
    node->left = NULL;
    node->right = NULL;
    return node;
}
