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
    system("cls");
    char view_all_book[100];
    printf("---------------------------------\n");
    printf("\tAvailable all books\n");
    printf("---------------------------------\n");
    FILE *book;
    book = fopen("../Book_Stock/Book_Stock.txt", "r");

    if (book == NULL)
    {
        printf("---------------------------------\n");
        printf("file does not exist\n");
        printf("---------------------------------\n");

        Sleep(1500);
    }
    printf("ISBN\tTitle\n");
    printf("----\t-----\n");
    do
    {
        fgets(view_all_book, sizeof(view_all_book), book);
        printf("%s", view_all_book);
        

    } while (!feof(book));
    Sleep(5000);
    if (profile_type == 1)
    {
        admin();
    }
    else
    {
        localUser();
    }
}
