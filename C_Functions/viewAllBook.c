// #include "addBook.h"
#include "admin.h"
// #include "deleteBook.h"
#include "localUser.h"
// #include "login.h"
// #include "orderBook.h"
// #include "registerUser.h"
// #include "viewAllBook.h"
// #include "viewBookDetails.h"

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

void viewAllBook(int profile_type)
{
    char next;

    system("cls");
    printf("---------------------------------\n");
    printf("\tAll available books\n");
    printf("---------------------------------\n");

    FILE *book;
    book = fopen("../Book_Stock/Book_Stock.txt", "r");

    if (book == NULL)
    {
        printf("file does not exist\n");
        Sleep(1500);
        if (profile_type == 1)
        {
            admin();
        }
        else
        {
            localUser();
        }
        return;
    }

    printf("ISBN\t-Title\t-Quantity\n");
    printf("---------------------------------\n");

    char view_all_book[100];
    while (fgets(view_all_book, sizeof(view_all_book), book) != NULL)
    {
        printf("%s", view_all_book);
    }

    fclose(book);
    printf("---------------------------------\n");
    do
    {
        printf("Enter 'y' to return: ");
        scanf(" %c", &next);
        printf("\n---------------------------------\n");
        next = tolower(next);
    } while (next != 'y');
    if (profile_type == 1)
    {
        admin();
    }
    else
    {
        localUser();
    }
}