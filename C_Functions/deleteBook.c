#include "admin.h"

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void deleteBook()
{
    int delete;
    char ISBN[200];
    char filename[200];
    char choice;
    do
    {
        getchar();
        printf("Enter ISBN: ");
        fgets(ISBN, sizeof(ISBN), stdin);
        ISBN[strcspn(ISBN, "\n")] = '\0';

        sprintf(filename, "../BookShop/%s.txt", ISBN);

        FILE *pDelF = fopen(filename, "r");
        if (pDelF == NULL)
        {
            printf("Unable to access data");
        }
        else
        {
            fclose(pDelF);
            delete = remove(filename);
            if (delete == 0)
            {
                printf("%s Removed Successfully !!\n", ISBN);
            }
            else
            {
                printf("Error: Unable to remove %s\n", ISBN);
            }
        }
        fclose(pDelF);
        printf("Do you want to remove another book ? (Y/N): ");
        scanf(" %c", &choice);
        choice = tolower(choice);
    } while (choice == 'y');
}