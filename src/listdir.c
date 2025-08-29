/**
 * @file listdir.c
 * @brief Lists the contents of a specified directory.
 *
 * This file contains a function to open a directory and print all its
 * files and subdirectories, excluding the special entries "." and "..".
 */

#include "listdir.h"
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

/**
 * @brief Lists all files and directories inside the specified directory.
 *
 * Opens the directory using opendir(), iterates through each entry
 * using readdir(), and prints the entry names. Skips the "." and ".."
 * entries. Prints an error message if the directory cannot be opened.
 *
 * @param dirpath The path of the directory to list.
 */
void listDirectory(const char *dirpath) {
    DIR *dir = opendir(dirpath);
    if (!dir) {
        perror("Error opening directory");
        return;
    }

    struct dirent *entry;

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        printf("%s\n", entry->d_name);
    }

    closedir(dir);
}