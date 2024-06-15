#include "localUser.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>


void orderBook()
{
    system("cls");
    char ret;
    char ISBN[200];
    char filename[200];
    char registered_single_record[200];
    int user_preference;
    int ord_Quantity;
    float bill;
    char view_all_book[200];

    printf("---------------------------------\n");
    printf("\tOrder Book\n");
    printf("---------------------------------\n");
//######################################################################
FILE *book_det = fopen("../Book_Stock/Book_Stock.txt", "r");
    printf("ISBN\tTitle\tQuantity\n");
    printf("---------------------------------\n");

    do
    {
        memset(view_all_book, 0, sizeof(book_det)); // clear the previous record
        fgets(view_all_book, sizeof(view_all_book), book_det);
        printf("%s", view_all_book);

    } while (!feof(book_det));
    printf("---------------------------------\n");
    fclose(book_det);
//######################################################################
    printf("Enter,\n");
    getchar();
    printf("ISBN: ");
    fgets(ISBN, sizeof(ISBN), stdin);
    ISBN[strcspn(ISBN, "\n")] = '\0';

    sprintf(filename, "../BookShop/%s.txt", ISBN);

    FILE *pOrdF = fopen(filename, "r");
    if (pOrdF == NULL)
    {
        printf("-----------------------\n");
        printf("File is unavailable\n");
        printf("-----------------------\n");
    }
    else
    {
        while (fgets(registered_single_record, sizeof(registered_single_record), pOrdF) != NULL)
        {
            registered_single_record[strcspn(registered_single_record, "\n")] = '\0';

            char *title = strtok(registered_single_record, "\t");
            char *author = strtok(NULL, "\t");
            char *pub_Year = strtok(NULL, "\t");
            char *isbn = strtok(NULL, "\t");
            char *price_str = strtok(NULL, "\t");
            char *quantity_str = strtok(NULL, "\t");

            float price = atof(price_str);
            int quantity = atoi(quantity_str);
            if (isbn != NULL && title != NULL)
            {
                user_preference = strcmp(isbn, ISBN);
                if (user_preference == 0)
                {
                    printf("Title: %s\n", title);
                    printf("Enter the quantity: ");
                    scanf("%d", &ord_Quantity);
                    bill = price * ord_Quantity;
                    // Enter decoration lines
                    printf("\n-----------------------\n");
                    printf("Your bill is: %.2f x %d = %.2f\n", price, ord_Quantity, bill);
                    printf("-----------------------\n");

                    FILE *upTXTf = fopen(filename, "w");
                    fprintf(upTXTf, "%s\t%s\t%s\t%s\t%.2f\t%d", title, author, pub_Year, isbn, price, (quantity - ord_Quantity));
                    fclose(upTXTf);

                    // Enter decoration lines
                    printf("-----------------------\n");

                    printf("Return Back (Y): ");
                    scanf(" %c", &ret);
                    ret = tolower(ret);
                    if (ret == 'y')
                    {
                        localUser();
                    }
                }
                else
                {
                    printf("-----------------------\n");
                    printf("Book is unavailable\n");
                    printf("-----------------------\n");
                    Sleep(2000);

                    orderBook();
                }
                printf("%s-%s", isbn, title);
            }
        }
    }

    fclose(pOrdF);
}


/*
void orderBook()
{
    system("cls");
    char ret;
    char ISBN[200];
    char filename[200];
    char lines[200];
    char registered_single_record[200];
    int user_preference;
    int ord_Quantity;
    float bill;
    char view_all_book[200];

    printf("---------------------------------\n");
    printf("\tOrder Book\n");
    printf("---------------------------------\n");
    // ###########################################  -> Enter list
    FILE *book_det = fopen("../Book_Stock/Book_Stock.txt", "r");
    printf("ISBN\tTitle\tQuantity\n");
    printf("---------------------------------\n");

    do
    {
        memset(view_all_book, 0, sizeof(book_det)); // clear the previous record
        fgets(view_all_book, sizeof(view_all_book), book_det);
        printf("%s", view_all_book);

    } while (!feof(book_det));
    printf("---------------------------------\n");
    fclose(book_det);
    // ###########################################
    printf("Enter,\n");
    getchar();
    printf("ISBN: ");
    fgets(ISBN, sizeof(ISBN), stdin);
    ISBN[strcspn(ISBN, "\n")] = '\0';

    sprintf(filename, "../BookShop/%s.txt", ISBN);

    FILE *pOrdF = fopen(filename, "r");
    if (pOrdF == NULL)
    {
        printf("---------------------------------\n");
        printf("File is unavailable\n");
        printf("---------------------------------\n");
        Sleep(1300);
        orderBook();
    }
    else
    {
        while (fgets(registered_single_record, sizeof(registered_single_record), pOrdF) != NULL)
        {
            registered_single_record[strcspn(registered_single_record, "\n")] = '\0';

            char *title = strtok(registered_single_record, "\t");
            char *author = strtok(NULL, "\t");
            char *pub_Year = strtok(NULL, "\t");
            char *isbn = strtok(NULL, "\t");
            char *price_str = strtok(NULL, "\t");
            char *quantity_str = strtok(NULL, "\t");

            float price = atof(price_str);
            int quantity = atoi(quantity_str);
            if (isbn != NULL && title != NULL)
            {
                user_preference = strcmp(isbn, ISBN);
                if (user_preference == 0)
                {
                    printf("Title: %s\n", title);
                    printf("Enter the quantity: ");
                    scanf("%d", &ord_Quantity);
                    bill = price * ord_Quantity;

                    printf("\n---------------------------------\n");
                    printf("Your bill is: %.2f x %d = %.2f\n", price, ord_Quantity, bill);
                    printf("---------------------------------\n");
                    fclose(pOrdF);
                    FILE *upTXTf = fopen(filename, "w");
                    int rev_quantity = quantity - ord_Quantity;
                    fprintf(upTXTf, "%s\t%s\t%s\t%s\t%.2f\t%d", title, author, pub_Year, isbn, price, rev_quantity);
                    fclose(upTXTf);

                    printf("Return Back (Y): ");
                    scanf(" %c", &ret);
                    ret = tolower(ret);
                    if (ret == 'y')
                    {
                        localUser();
                    }
                    orderBook();
                }
                else
                {
                    printf("-----------------------\n");
                    printf("Book is unavailable\n");
                    printf("-----------------------\n");
                    Sleep(1500);

                    orderBook();
                }
                printf("%s-%s", isbn, title);
            }
        }
    }

    fclose(pOrdF);
}
*/
//#########################################################################################################
