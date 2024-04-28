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
#include <stdlib.h>
#include <ctype.h>

void viewBookDetails(int profile_type) // 1-admin, 0-local user
{

    system("cls");
    char ISBN[100];
    char F_ISBN[110];
    char Read_Record[100];
    char nav_back;

    printf("---------------------------------\n");
    printf("\tView Book Details\n");
    printf("---------------------------------\n\n");

    printf("Enter the ISBN : ");
    getchar();
    fgets(ISBN, sizeof(ISBN), stdin);
    ISBN[strcspn(ISBN, "\n")] = '\0';
    printf("---------------------------------\n");
    sprintf(F_ISBN, "../BookShop/%s.txt", ISBN);

    FILE *F_File = fopen(F_ISBN, "r");
    if (F_File == NULL)
    {
        printf("Unable to find the book\n");
        printf("---------------------------------\n");
        Sleep(2500);
        fclose(F_File);

        if (profile_type == 1)
        {
            admin();
        }
        else if (profile_type == 0)
        {
            localUser();
        }
    }
    else
    {
        FILE *F_File = fopen(F_ISBN, "r");
        while (fgets(Read_Record, sizeof(Read_Record), F_File) != NULL)
        {
            Read_Record[strcspn(Read_Record, "\n")] = '\0';

            char *title = strtok(Read_Record, "\t");
            char *Author = strtok(NULL, "\t");
            char *P_Year = strtok(NULL, "\t");
            char *Isbn = strtok(NULL, "\t");
            char *Price = strtok(NULL, "\t");
            char *Quantity = strtok(NULL, "\t");

            printf("Title:\t\t%s\nAuthor:\t\t%s\nPublished Year:\t%s\nPrice:\t\t%s\nQuantity:\t%s", title, Author, P_Year, Price, Quantity);

            printf("\n---------------------------------\n");
        }
        do
        {
            printf("Return back Y/N: ");
            scanf(" %c", &nav_back);
            nav_back = tolower(nav_back);

            if (nav_back == 'y')
            {
                if (profile_type == 1)
                {
                    admin();
                    break;
                }
                else if (profile_type == 0)
                {
                    localUser();
                    break;
                }
            }
            else if (nav_back == 'n')
            {
                viewBookDetails(profile_type);
            }
            else
            {
                printf("Enter valid option!");
            }
        } while (nav_back != 'y');
    }
    fclose(F_File);
}