#include "login.h"
#include "orderBook.h"
#include "viewAllBook.h"
#include "viewBookDetails.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void localUser()
{

    system("cls");

    bool break_while = false;
    int loc_choice;

    printf("---------------------------------\n");
    printf("\tLocal User Profile\n");
    printf("---------------------------------\n");

    printf("1.  View all books\n");
    printf("2.  View book Details\n");
    printf("3.  Order book\n");
    printf("99. Exit\n");

    printf("\nEnter your choice: ");
    scanf("%d", &loc_choice);
    switch (loc_choice)
    {
    case 1:
        viewAllBook(0);
        break_while = true;
        break;
    case 2:
        viewBookDetails(0);
        break_while = true;
        break;
    case 3:
        orderBook();
        break_while = true;
        break;
    case 99:
        printf("\n---------------------------------\n");
        printf("Exiting!");
        break_while = false;
        Sleep(1500);
        login();
        break;
    default:
        printf("\n---------------------------------\n");
        printf("Enter valid choice\n");
        printf("---------------------------------\n");

        Sleep(1500);
        localUser();
        break;
    }
}