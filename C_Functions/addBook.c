// #include "addBook.h"
#include "admin.h"
// #include "deleteBook.h"
// #include "localUser.h"
// #include "login.h"
// #include "orderBook.h"
// #include "registerUser.h"
// #include "viewAllBook.h"
// #include "viewBookDetails.h"

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// void clNewLChara()
// {
//     int c;
//     while ((c = getchar()) != '\n' && c != EOF)
//         ;
// }

void addBook()
{
    system("cls");

    char title[200];
    char author[200];
    int pub_year;
    char ISBN[200];
    float price;
    char fileName[210];
    char Next;
    int quantity;

    printf("-----------------------\n");
    printf("\tAdd Book\n");
    printf("-----------------------\n");
    do
    {
        printf("Enter, \n\n");
       
        printf("Book Title : ");
        getchar();
        fgets(title, sizeof(title), stdin); // read spaces
        title[strcspn(title, "\n")] = '\0'; // remove the new line character at end

        printf("Author : ");
        getchar();
        fgets(author, sizeof(author), stdin);
        author[strcspn(author, "\n")] = '\0';

        printf("Published Year : ");
        getchar();
        scanf("%d", &pub_year);

        printf("ISBN : ");
        getchar();
        scanf(" %s", ISBN);

        printf("Price : ");
        getchar();
        scanf("%f", &price);

        printf("Quantity : ");
        getchar();
        scanf("%d", &quantity);

        sprintf(fileName, "../BookShop/%s.txt", ISBN);

        FILE *pFile = fopen(fileName, "r");
        if (pFile != NULL)
        {
            printf("-----------------------\n");
            printf("Book already exists.");
            fclose(pFile);
        }
        else
        {
            pFile = fopen(fileName, "w");
            if (pFile == NULL)
            {
                printf("-----------------------\n");
                printf("Book unsuccessfully added.");
            }
            else
            {
                fprintf(pFile, "%s\t%s\t%d\t%s\t%.2f\t%d", title, author, pub_year, ISBN, price, quantity);
                printf("-----------------------\n");
                printf("Book successfully added.");

                FILE *pBD = fopen("../Book_Stock/Book_Stock.txt", "a");
                fprintf(pBD, "%s\t%s\t%d\n", ISBN, title, quantity);
                fclose(pBD);
            }
            fclose(pFile);
        }

        printf("\n\nAdd another book Y/N : ");
        scanf(" %c", &Next);
        getchar(); // remove new line
        printf("-----------------------\n");

        Next = tolower(Next); // remove case sensitiveness

    } while (Next != 'n');
    admin();
}
