/**
 * @file copyfile.c
 * @brief Copies the contents of one file to another.
 *
 * This file contains a function to copy data from a source file
 * to a destination file character by character. If the destination
 * file does not exist, it will be created.
 */

#include "copyfile.h"
#include <stdio.h>

/**
 * @brief Copies the content of the source file to the destination file.
 *
 * Opens the source file in read mode and the destination file in write mode.
 * Reads the source file character by character and writes each character
 * to the destination file. Handles errors if either file cannot be opened.
 *
 * @param source The path of the source file to copy from.
 * @param destination The path of the destination file to copy to.
 */
void copyFile(const char *source, const char *destination) {
    FILE *src = fopen(source, "r");
    if (!src) {
        perror("Error opening source file");
        return;
    }

    FILE *dest = fopen(destination, "w");
    if (!dest) {
        perror("Error opening destination file");
        fclose(src);
        return;
    }

    char ch;
    while ((ch = fgetc(src)) != EOF) {
        fputc(ch, dest);
    }

    printf("File copied from '%s' to '%s'\n", source, destination);

    fclose(src);
    fclose(dest);
}