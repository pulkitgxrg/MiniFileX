#include "./appendfile.h"
#include "./copyfile.h"
#include "./createdir.h"
#include "./createfile.h"
#include "./deletedir.h"
#include "./deletefile.h"
#include "./listdir.h"
#include "./movefile.h"
#include "./readfile.h"
#include "./renamefile.h"
#include "./writefile.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Entry point of the Mini File Management System.
 *
 * Provides a menu-driven interface to perform basic file and directory
 * operations such as create, write, append, copy, read, delete, rename,
 * move, create directory, delete directory, and list directory contents.
 *
 * @return 0 on successful execution.
 */
int main() {
    int choice;
    char file1[256];
    char file2[256];

    while (1) {
        printf("\n===== Mini File Management System =====\n");
        printf("1. Create File\n");
        printf("2. Write File\n");
        printf("3. Append File\n");
        printf("4. Copy File\n");
        printf("5. Read File\n");
        printf("6. Delete File\n");
        printf("7. Rename File\n");
        printf("8. Move File\n");
        printf("9. Create Directory\n");
        printf("10. Delete Directory\n");
        printf("11. List Directory Contents\n");
        printf("12. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter filename: ");
            scanf("%255s", file1);
            createFile(file1);
            break;
        case 2:
            printf("Enter filename: ");
            scanf("%255s", file1);
            writeFile(file1);
            break;
        case 3:
            printf("Enter filename: ");
            scanf("%255s", file1);
            appendFile(file1);
            break;
        case 4:
            printf("Enter source filename: ");
            scanf("%255s", file1);
            printf("Enter destination filename: ");
            scanf("%255s", file2);
            copyFile(file1, file2);
            break;
        case 5:
            printf("Enter filename: ");
            scanf("%255s", file1);
            readFile(file1);
            break;
        case 6:
            printf("Enter filename to delete: ");
            scanf("%255s", file1);
            deleteFile(file1);
            break;
        case 7:
            printf("Enter current filename: ");
            scanf("%255s", file1);
            printf("Enter new filename: ");
            scanf("%255s", file2);
            renameFile(file1, file2);
            break;
        case 8:
            printf("Enter source file path: ");
            scanf("%255s", file1);
            printf("Enter destination file path: ");
            scanf("%255s", file2);
            moveFile(file1, file2);
            break;
        case 9:
            printf("Enter directory name to create: ");
            scanf("%255s", file1);
            createDirectory(file1);
            break;
        case 10:
            printf("Enter directory name to delete: ");
            scanf("%255s", file1);
            deleteDirectory(file1);
            break;
        case 11:
            printf("Enter directory path to list: ");
            scanf("%255s", file1);
            listDirectory(file1);
            break;
        case 12:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice, try again.\n");
        }
    }

    return 0;
}
