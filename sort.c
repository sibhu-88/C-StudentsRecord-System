/*
 *=========================================================
 *  Project : Student Record Management System
 *  File    : sort.c
 *  Author  : Prabhu
 *=========================================================
 */

#include "header.h"

/*---------------------------------------------------------
            Sort Student Records
---------------------------------------------------------*/
void sort_student_list(SDB *head)
{
    char choice;
    int count, i;
    SDB **arr;
    SDB *temp;

    if (head == NULL)
    {
        printf("\nNo Student Records Available.\n");
        return;
    }

    display_sort_menu();

    scanf(" %c", &choice);
    choice = tolower(choice);

    if (choice == 'b')
        return;

    count = count_records(head);

    arr = (SDB **)malloc(count * sizeof(SDB *));

    if (arr == NULL)
    {
        printf("\nMemory Allocation Failed.\n");
        return;
    }

    temp = head;

    for (i = 0; i < count; i++)
    {
        arr[i] = temp;
        temp = temp->next;
    }

    switch (choice)
    {
        case 'n':
            sort_by_name(arr, count);
            break;

        case 'p':
            sort_by_percentage(arr, count);
            break;

        default:
            printf("\nInvalid Choice.\n");
            free(arr);
            return;
    }

    print_sorted_records(arr, count);

    free(arr);
}

/*---------------------------------------------------------
        Sort By Student Name (Ascending)
---------------------------------------------------------*/
void sort_by_name(SDB **arr, int count)
{
    int i, j;
    SDB *temp;

    for (i = 0; i < count - 1; i++)
    {
        for (j = 0; j < count - i - 1; j++)
        {
            if (strcasecmp(arr[j]->name, arr[j + 1]->name) > 0)
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

/*---------------------------------------------------------
    Sort By Percentage (Descending)
---------------------------------------------------------*/
void sort_by_percentage(SDB **arr, int count)
{
    int i, j;
    SDB *temp;

    for (i = 0; i < count - 1; i++)
    {
        for (j = 0; j < count - i - 1; j++)
        {
            if (arr[j]->percentage < arr[j + 1]->percentage)
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

/*---------------------------------------------------------
        Display Sorted Student Records
---------------------------------------------------------*/
void print_sorted_records(SDB **arr, int count)
{
    int i;

    printf("\n");
    printf("=================================================================\n");
    printf("| %-8s | %-25s | %-12s |\n",
           "Roll No",
           "Student Name",
           "Percentage");
    printf("=================================================================\n");

    for (i = 0; i < count; i++)
    {
        printf("| %-8d | %-25s | %-10.2f%% |\n",
               arr[i]->rollno,
               arr[i]->name,
               arr[i]->percentage);
    }

    printf("=================================================================\n");
    printf("Total Records : %d\n", count);
}