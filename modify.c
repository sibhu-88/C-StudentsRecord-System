/*
 *=========================================================
 *  Project : Student Record Management System
 *  File    : modify.c
 *  Author  : Prabhu
 *=========================================================
 */

#include "header.h"

/*---------------------------------------------------------
                Modify Student Record
---------------------------------------------------------*/
void modify_record(SDB **head)
{
    char choice;

    if (*head == NULL)
    {
        printf("\nNo Records Available.\n");
        return;
    }

    while (1)
    {
        display_modify_menu();

        scanf(" %c", &choice);
        choice = tolower(choice);

        switch (choice)
        {
            case 'r':
                modify_by_rollno(*head);
                return;

            case 'n':
                modify_by_name(*head);
                return;

            case 'b':
                return;

            default:
                printf("\nInvalid Choice! Please Try Again.\n");
        }
    }
}

/*---------------------------------------------------------
            Modify by Roll Number
---------------------------------------------------------*/
void modify_by_rollno(SDB *head)
{
    int rollno;
    SDB *record;

    printf("\nEnter Roll Number : ");
    scanf("%d", &rollno);

    record = search_by_rollno(head, rollno);

    if (record == NULL)
    {
        printf("\nRecord Not Found.\n");
        return;
    }

    modify_record_options(record);
}

/*---------------------------------------------------------
            Modify by Student Name
---------------------------------------------------------*/
void modify_by_name(SDB *head)
{
    char name[NAME_SIZE];
    SDB *record;

    printf("\nEnter Student Name : ");
    scanf("%49s", name);

    record = search_by_name(head, name);

    if (record == NULL)
    {
        printf("\nRecord Not Found.\n");
        return;
    }

    modify_record_options(record);
}

/*---------------------------------------------------------
            Modify Record Options
---------------------------------------------------------*/
void modify_record_options(SDB *record)
{
    char choice;
    char confirm;

    char new_name[NAME_SIZE];
    float new_percentage;

    printf("\n=====================================\n");
    printf("         STUDENT RECORD FOUND\n");
    printf("=====================================\n");
    printf("Roll Number : %d\n", record->rollno);
    printf("Name        : %s\n", record->name);
    printf("Percentage  : %.2f\n", record->percentage);
    printf("=====================================\n");

    display_modify_options_menu();

    scanf(" %c", &choice);
    choice = tolower(choice);

    switch (choice)
    {
        case 'n':

            printf("\nEnter New Name : ");
            scanf("%49s", new_name);

            printf("Save Changes? (Y/N) : ");
            scanf(" %c", &confirm);

            if (tolower(confirm) == 'y')
            {
                strcpy(record->name, new_name);
                printf("\nName Updated Successfully.\n");
            }
            else
            {
                printf("\nModification Cancelled.\n");
            }

            break;

        case 'p':

            printf("\nEnter New Percentage : ");
            scanf("%f", &new_percentage);

            if (new_percentage < 0 || new_percentage > 100)
            {
                printf("\nInvalid Percentage.\n");
                return;
            }

            printf("Save Changes? (Y/N) : ");
            scanf(" %c", &confirm);

            if (tolower(confirm) == 'y')
            {
                record->percentage = new_percentage;
                printf("\nPercentage Updated Successfully.\n");
            }
            else
            {
                printf("\nModification Cancelled.\n");
            }

            break;

        case 'b':
            return;

        default:
            printf("\nInvalid Choice.\n");
    }
}