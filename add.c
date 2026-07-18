/*
 *=========================================================
 *  Project : Student Record Management System
 *  File    : add.c
 *  Author  : Prabhu
 *=========================================================
 */

#include "header.h"

/*---------------------------------------------------------
            Add New Student Record
---------------------------------------------------------*/
void add_new_record(SDB **head)
{
    SDB *newnode;
    SDB *temp;

    newnode = (SDB *)malloc(sizeof(SDB));

    if (newnode == NULL)
    {
        printf("\nMemory Allocation Failed.\n");
        return;
    }

    /*--------------- Auto Generate Roll Number ----------------*/

    newnode->rollno = generate_rollno(*head);

    printf("\nGenerated Roll Number : %d\n", newnode->rollno);

    /*--------------- Student Name ----------------*/

    while (1)
    {
        printf("Enter Student Name : ");

        scanf("%49s", newnode->name);

        if (strlen(newnode->name) == 0)
        {
            printf("Name cannot be empty.\n");
            continue;
        }

        break;
    }

    /*--------------- Percentage ----------------*/

    while (1)
    {
        printf("Enter Percentage : ");

        if (scanf("%f", &newnode->percentage) != 1)
        {
            printf("Invalid Percentage.\n");

            while (getchar() != '\n');

            continue;
        }

        if (newnode->percentage < 0.0 || newnode->percentage > 100.0)
        {
            printf("Percentage must be between 0 and 100.\n");
            continue;
        }

        break;
    }

    newnode->next = NULL;

    /*--------------- Insert Record ----------------*/

    if (*head == NULL)
    {
        *head = newnode;
    }
    else
    {
        temp = *head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newnode;
    }

    printf(" Student Record Added Successfully\n");
    
    // printf("\n=========================================\n");
    // printf("=========================================\n");
    // printf(" Roll Number : %d\n", newnode->rollno);
    // printf(" Name        : %s\n", newnode->name);
    // printf(" Percentage  : %.2f\n", newnode->percentage);
    // printf("=========================================\n");
}