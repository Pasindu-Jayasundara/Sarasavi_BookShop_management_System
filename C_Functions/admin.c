#include "addBook.h"
#include "deleteBook.h"
#include "login.h"
#include "viewAllBook.h"
#include "viewBookDetails.h"

#include <stdio.h>
#include <stdlib.h> 
#include <windows.h>

void admin(){
   system("cls");

    int ad_choice;

    printf("---------------------------------\n");
    printf("\tAdmin Profile\n");
    printf("---------------------------------\n");

    printf("1.  Add Book\n");
    printf("2.  Delete Book\n");
    printf("3.  View all books\n");
    printf("4.  View book Details\n");
    printf("99. Exit\n\n");

    printf("Enter your choice: ");
    scanf("%d", &ad_choice);
    switch (ad_choice)
    {
    case 1:
        addBook();
        break;
    case 2:
        deleteBook();
        break;
    case 3:
        viewAllBook(1);
        break;
    case 4:
        viewBookDetails(1);
        break;
    case 99:
        printf("Exiting!");
        login();
        break;
    default:
        printf("\nEnter Valid choice\n");
        Sleep(1500); // Delay the message for 1.5 seconds, in UNIX use sleep, in Windows use Sleep

        admin(); //selfCall
        break;
    }
}