/*
** EPITECH PROJECT, 2025
** emalloc (exits when malloc failed)
** File description:
** emalloc
*/

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include "utils/memory_utils.h"

void *emalloc(size_t size)
{
    void *ptr = malloc(size);

    if (ptr == NULL) {
        write(2, "malloc failed\n", 14);
        exit(84);
    }
    return ptr;
}
