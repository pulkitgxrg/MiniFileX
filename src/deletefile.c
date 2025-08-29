/**
 * @file deletefile.c
 * @brief Deletes a specified file from the filesystem.
 *
 * This file contains a function to delete a file using the standard
 * C library remove() function. It prints messages indicating whether
 * the deletion succeeded or failed.
 */

#include "deletefile.h"
#include <errno.h>
#include <stdio.h>

/**
 * @brief Deletes a file with the given name.
 *
 * Attempts to remove the specified file. On success, prints a confirmation
 * message. On failure, prints the associated system error message.
 *
 * @param filename The name or path of the file to delete.
 */
void deleteFile(const char *filename) {
    if (remove(filename) == 0) {
        printf("File '%s' deleted successfully!\n", filename);
    } else {
        perror("Error deleting file");
    }
}