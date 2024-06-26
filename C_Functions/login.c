// #include "addBook.h"
// #include "admin.h"
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

void login()
{
    
    system("cls");
    getchar();
    char Next;
    char uname[100];
    char pass[100];
    char registered_single_record[100];
    int user_name = 0;
    int pass_word = 0;
    int log_unsuccess = 0;

    char admin_arr[] = "admin";
    int admin_comparison = 0;

    printf("----------------------\n");
    printf("\tLogin\n");
    printf("----------------------\n");
    do
    {
        printf("Enter,\n\n");
        printf("User Name: ");
        fgets(uname, sizeof(uname), stdin);
        uname[strcspn(uname, "\n")] = '\0';

        printf("Password: ");
        fgets(pass, sizeof(pass), stdin);
        pass[strcspn(pass, "\n")] = '\0';

        FILE *pCheck_File = fopen("../Registrations/Registration_details.txt", "r");
        if (pCheck_File == NULL)
        {
            printf("----------------------\n");
            printf("Error while logging\n");
            printf("----------------------\n");
            Sleep(1500);
            login();
        }
        else
        {
            while (fgets(registered_single_record, sizeof(registered_single_record), pCheck_File) != NULL)
            {
                registered_single_record[strcspn(registered_single_record, "\n")] = '\0';
                char *username = strtok(registered_single_record, "\t");
                char *password = strtok(NULL, "\t");

                if (username != NULL && password != NULL)
                {
                    user_name = strcmp(username, uname); // compare user name with file user name
                    pass_word = strcmp(password, pass);  // compare Passwords
                    admin_comparison = strcmp(uname, admin_arr);

                    if (user_name == 0 && pass_word == 0) // go in when match found then exits.
                    {
                        log_unsuccess = 1;
                        printf("----------------------\n");
                        printf("Login successful!\n");
                        printf("----------------------\n");
                        Sleep(1300);

                        if (admin_comparison == 0)
                        {
                            admin();
                            break;
                        }
                        else
                        {
                            localUser();
                            break;
                        }
                        fclose(pCheck_File);
                        // return 1; // Return 1 to indicate successful login  ####<-- user profile function <--####
                    }
                }
            }
        }
        if (log_unsuccess)
        {
            printf("\n----------------------\n");
            printf("Invalid username or password!\n");
            printf("----------------------\n");
        }
        fclose(pCheck_File);

        printf("\n----------------------\n");
        printf("Invalid username or password!\n");
        printf("----------------------\n");

        printf("Log again Y/N: ");
        scanf(" %c", &Next);
        printf("----------------------\n");
        Next = tolower(Next);
        getchar(); // to recurse the loop correctly
    } while (Next == 'y');
    login();
}