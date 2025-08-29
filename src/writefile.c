/**
 * @file writefile.c
 * @brief Writes text to a file, overwriting existing content.
 *
 * This file contains a function to write user-provided text to a file.
 * If the file already exists, its contents will be overwritten.
 */

#include "writefile.h"
#include <stdio.h>

/**
 * @brief Writes user input to the specified file.
 *
 * Opens the file in write mode, reads a line of text from the user,
 * and writes it to the file, replacing any existing content.
 *
 * @param filename The name/path of the file to write to.
 */
void writeFile(const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Error opening file for writing");
        return;
    }

    char data[200];

    printf("Enter text to write (end with ENTER):\n");

    getchar();
    fgets(data, sizeof(data), stdin);
    fputs(data, fp);

    printf("Data written to '%s'\n", filename);

    fclose(fp);
}