/*
** EPITECH PROJECT, 2025
** handle the path variable to launch the commands
** File description:
** path_handling
*/

#include <unistd.h>
#include <stdlib.h>
#include "utils/minilib.h"
#include "utils/string_utils.h"
#include "utils/memory_utils.h"
#include "execution/execution.h"

char *concat_path(char *path, char *command)
{
    char *temp = my_strcat(path, "/");
    char *result = my_strcat(temp, command);

    free(temp);
    return result;
}

void cleanup_path_array(char **path_array)
{
    for (int i = 0; path_array[i]; i++)
        free(path_array[i]);
    if (path_array)
        free(path_array);
}

char *try_path_locations(char **path_array, char *command)
{
    char *new_path = NULL;

    for (int i = 0; path_array[i]; i++) {
        new_path = concat_path(path_array[i], command);
        if (access(new_path, F_OK) == 0) {
            cleanup_path_array(path_array);
            return new_path;
        }
        free(new_path);
    }
    cleanup_path_array(path_array);
    return NULL;
}

char *get_fullpath(char *command, char **env)
{
    char *path = my_getenv(env, "PATH");
    char **path_array = NULL;
    char *result = NULL;

    if (!path)
        return NULL;
    if (command[0] != '.' && command[0] != '/') {
        path_array = my_str_to_word_array(path, ':');
        result = try_path_locations(path_array, command);
        if (result)
        return result;
    }
    if (access(command, F_OK) == 0)
        return my_strdup(command);
    write(2, command, my_strlen(command));
    write(2, ": Command not found.\n", 21);
    return NULL;
}
