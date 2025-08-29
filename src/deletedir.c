/**
 * @file deletedir.c
 * @brief Recursive directory deletion for Linux/macOS.
 *
 * This file contains functions to delete a directory along with all its
 * contents, including files and subdirectories. It uses POSIX functions
 * such as opendir(), readdir(), unlink(), and rmdir().
 */

#include "deletedir.h"
#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

/**
 * @brief Recursively removes a directory and its contents.
 *
 * @param path The directory path to delete.
 * @return 0 on success, -1 on failure.
 */
static int removeDirectoryRecursive(const char *path) {
    DIR *dir = opendir(path);

    if (!dir)
        return rmdir(path);

    struct dirent *entry;
    char fullpath[1024];

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);

        struct stat st;
        if (lstat(fullpath, &st) == 0) {
            if (S_ISDIR(st.st_mode)) {
                if (removeDirectoryRecursive(fullpath) != 0) {
                    closedir(dir);
                    return -1;
                }
            } else {
                if (unlink(fullpath) != 0) {
                    closedir(dir);
                    return -1;
                }
            }
        }
    }

    closedir(dir);
    return rmdir(path);
}

/**
 * @brief Deletes a directory and its contents.
 *
 * @param dirname The directory path to delete.
 */
void deleteDirectory(const char *dirname) {
    if (removeDirectoryRecursive(dirname) == 0) {
        printf("Directory '%s' deleted successfully!\n", dirname);
    } else {
        perror("Error deleting directory");
    }
}