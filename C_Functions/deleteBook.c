#include "admin.h"

#include <stdio.h>
// #include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void deleteBook()
{
	//getchar();
    int delete, found;
    char ISBN[200];
    char stockISBN[10];
    char filename[220];
    char line[100];
    char bookStockPath[] = "../Book_Stock/Book_Stock.txt";
    char choice;

    do
    {
        system("clear");
        getchar();
        printf("---------------------------------\n");
        printf("\tDelete Book\n");
        printf("---------------------------------\n");
        //getchar();
        
        printf("Enter ISBN: ");
        fgets(ISBN, sizeof(ISBN), stdin);
        ISBN[strcspn(ISBN, "\r\n")] = '\0';

        sprintf(filename, "../BookShop/%s.txt", ISBN);

        FILE *pDelF = fopen(filename, "r");
        FILE *stockDelf = fopen(bookStockPath, "r");
        FILE *temp = fopen("temp.txt", "w");

	//##############################################

	if(pDelF == NULL){
	printf("\nInvalid ISBN!!\n");
	//getchar();
	//fclose(pDelF);
	sleep(1.5);
	deleteBook();
	//
	}

	//##############################################

        if (temp == NULL)
        {
            printf("---------------------------------\n");
            printf("Error creating temporary file\n");
            printf("---------------------------------\n");

            fclose(stockDelf);
            return;
        }

        while (fgets(line, 100, stockDelf) != NULL)
        {
            if (strstr(line, ISBN) != NULL)
            {
                found = 1;
                continue;
            }
            fputs(line, temp);
        }
        fclose(stockDelf);
        fclose(temp);

        remove(bookStockPath);
        rename("temp.txt", bookStockPath);

        if (pDelF == NULL)
        {
            printf("\n---------------------------------\n");
            printf("Unable to remove book %s !!", ISBN);
        }
        else
        {
            fclose(pDelF);
            delete = remove(filename);

            if (delete == 0)
            {
                printf("---------------------------------\n");
                printf("%s Removed Successfully !!", ISBN);
            }
        }
        //fclose(pDelF);
        printf("\n---------------------------------\n");
        printf("Do you want to remove another book ? (Y/N): ");
        scanf(" %c", &choice);
        choice = tolower(choice);
    } while (choice == 'y');
    admin();
}
