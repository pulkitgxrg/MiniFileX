/**
 * @file movefile.c
 * @brief Moves a file from a source path to a destination path.
 *
 * This file contains a function to move or rename a file using the standard
 * C library rename() function. Prints success or error messages depending
 * on the outcome.
 */

#include "movefile.h"
#include <stdio.h>

/**
 * @brief Moves a file from the source path to the destination path.
 *
 * Uses rename() to move the file. If the move succeeds, prints a confirmation.
 * If it fails, prints the corresponding system error message.
 *
 * @param sourcePath The current path of the file to move.
 * @param destinationPath The new path where the file should be moved.
 */
void moveFile(const char *sourcePath, const char *destinationPath) {
    if (rename(sourcePath, destinationPath) == 0) {
        printf("Moved '%s' to '%s'\n", sourcePath, destinationPath);
    } else {
        perror("Error moving file");
    }
}