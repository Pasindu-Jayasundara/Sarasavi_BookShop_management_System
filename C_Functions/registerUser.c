#include "login.h"

#include<stdio.h>
#include<stdlib.h>

void registerUser(){

    system("clear");
    
    char uname[100];
    char password[100];
    char conf_password[100];
    int comparison, whether_already_registered;
    char registered_value[100];

    printf("------------------------\n");
    printf("\tRegister\n");
    printf("------------------------\n");
    //getchar();
    printf("Enter,\n\n");

    printf("User Name: ");
    fgets(uname, sizeof(uname), stdin);
    uname[strcspn(uname, "\r\n")] = '\0'; // Remove newline character

    printf("Password: ");
    scanf("%s", password);

    printf("Confirm Password: ");
    scanf("%s", conf_password);

    comparison = strcmp(password, conf_password);

    if (comparison == 0)
    {
        FILE *pFile = fopen("../Registrations/Registration_details.txt", "r");
        if (pFile == NULL)
        {
            pFile = fopen("../Registrations/Registration_details.txt", "w");
            fclose(pFile);
        }
        else
        {
            while (fgets(registered_value, sizeof(registered_value), pFile) != NULL)
            {
                // Remove newline character if present
                registered_value[strcspn(registered_value, "\r\n")] = '\0';

                // Split the line into username and password
                char *token = strtok(registered_value, "\t");
                if (token != NULL)
                {
                    whether_already_registered = strcmp(token, uname);
                    if (whether_already_registered == 0)
                    {
                        printf("------------------------\n");
                        printf("You have already registered\n");
                        printf("------------------------\n");
                        sleep(1.5);
                        fclose(pFile);
                        login(); // login function here
                    }
                }
            }
            fclose(pFile);
        }

        pFile = fopen("../Registrations/Registration_details.txt", "a");
        fprintf(pFile, "%s\t%s\n", uname, password);
        fclose(pFile);
        printf("------------------------\n");
        printf("Registered Successfully\n");
        printf("------------------------\n");
        sleep(1.5);
        login();
    }
    else
    {
        printf("Passwords do not match\n\n");
        sleep(1.5);
        registerUser();
    }
}
