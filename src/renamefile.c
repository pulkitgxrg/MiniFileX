/**
 * @file renamefile.c
 * @brief Renames a file from an old name to a new name.
 *
 * This file contains a function to rename a file using the standard
 * C library rename() function. Prints success or error messages.
 */

#include "renamefile.h"
#include <stdio.h>

/**
 * @brief Renames a file from oldname to newname.
 *
 * Uses the rename() function to change the file name. On success,
 * prints a confirmation message. On failure, prints the associated
 * system error.
 *
 * @param oldname The current name/path of the file.
 * @param newname The new name/path for the file.
 */
void renameFile(const char *oldname, const char *newname) {
    if (rename(oldname, newname) == 0) {
        printf("File renamed from '%s' to '%s'\n", oldname, newname);
    } else {
        perror("Error renaming file");
    }
}