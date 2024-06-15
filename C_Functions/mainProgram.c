#include "login.h"
#include "registerUser.h"

#include "addBook.c"
#include "admin.c"
#include "deleteBook.c"
#include "localUser.c"
#include "login.c"
#include "orderBook.c"
#include "registerUser.c"
#include "viewAllBook.c"
#include "viewBookDetails.c"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main()
{
    system("cls");
    int LRchoice;
    bool break_while = false;

    printf("---------------------------------\n");
    printf("\tSarasavi Book Shop\n");
    printf("---------------------------------\n");
    printf("1. Login\n");
    printf("2. Register\n\n");
    do
    {
        printf("Enter your choice: ");
        scanf("%d", &LRchoice);
        printf("\n");

        if (LRchoice == 1)
        {
            break_while = true;
            login();
            break;
        }
        else if (LRchoice == 2)
        {
            break_while = true;
            registerUser();
            break;
        }
        else
        {
            printf("Enter Valid Choice Number\n\n");
            break_while = false;
        }
    } while (~break_while);
}