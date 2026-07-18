/*
 *=========================================================
 *  Project : Student Record Management System
 *  File    : delete.c
 *  Author  : Prabhu
 *=========================================================
 */

#include "header.h"

/*---------------------------------------------------------
            Delete Student Record
---------------------------------------------------------*/
void delete_record(SDB **head)
{
    char choice;

    if (*head == NULL)
    {
        printf("\nNo Records Available.\n");
        return;
    }

    while (1)
    {
        display_delete_menu();

        scanf(" %c", &choice);
        choice = tolower(choice);

        switch (choice)
        {
            case 'r':
                delete_record_by_rollno(head);
                return;

            case 'n':
                delete_record_by_name(head);
                return;

            case 'b':
                return;

            default:
                printf("\nInvalid Choice! Please Try Again.\n");
        }
    }
}

/*---------------------------------------------------------
        Delete Record by Roll Number
---------------------------------------------------------*/
void delete_record_by_rollno(SDB **head)
{
    int rollno;
    char confirm;

    SDB *temp = *head;
    SDB *prev = NULL;

    printf("\nEnter Roll Number : ");
    scanf("%d", &rollno);

    while (temp != NULL)
    {
        if (temp->rollno == rollno)
        {
            printf("\n=====================================\n");
            printf("        STUDENT RECORD FOUND\n");
            printf("=====================================\n");
            printf("Roll Number : %d\n", temp->rollno);
            printf("Name        : %s\n", temp->name);
            printf("Percentage  : %.2f\n", temp->percentage);
            printf("=====================================\n");

            printf("Delete this record? (Y/N) : ");
            scanf(" %c", &confirm);

            confirm = tolower(confirm);

            if (confirm == 'y')
            {
                if (prev == NULL)
                    *head = temp->next;
                else
                    prev->next = temp->next;

                free(temp);

                printf("\nRecord Deleted Successfully.\n");
            }
            else
            {
                printf("\nDeletion Cancelled.\n");
            }

            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("\nRoll Number %d Not Found.\n", rollno);
}

/*---------------------------------------------------------
        Delete Record by Student Name
---------------------------------------------------------*/
void delete_record_by_name(SDB **head)
{
    char name[NAME_SIZE];
    char confirm;

    SDB *temp = *head;
    SDB *prev = NULL;

    printf("\nEnter Student Name : ");
    scanf("%49s", name);

    while (temp != NULL)
    {
        if (strcasecmp(temp->name, name) == 0)
        {
            printf("\n=====================================\n");
            printf("        STUDENT RECORD FOUND\n");
            printf("=====================================\n");
            printf("Roll Number : %d\n", temp->rollno);
            printf("Name        : %s\n", temp->name);
            printf("Percentage  : %.2f\n", temp->percentage);
            printf("=====================================\n");

            printf("Delete this record? (Y/N) : ");
            scanf(" %c", &confirm);

            confirm = tolower(confirm);

            if (confirm == 'y')
            {
                if (prev == NULL)
                    *head = temp->next;
                else
                    prev->next = temp->next;

                free(temp);

                printf("\nRecord Deleted Successfully.\n");
            }
            else
            {
                printf("\nDeletion Cancelled.\n");
            }

            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("\nStudent \"%s\" Not Found.\n", name);
}