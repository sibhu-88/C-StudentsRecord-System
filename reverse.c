/*
 *=========================================================
 *  Project : Student Record Management System
 *  File    : reverse.c
 *  Author  : Prabhu
 *=========================================================
 */

#include "header.h"

/*---------------------------------------------------------
        Display Student Records in Reverse Order
---------------------------------------------------------*/
void reverse_student_list(SDB *head)
{
    int i, count;
    SDB **arr;
    SDB *temp;

    if (head == NULL)
    {
        printf("\nNo Student Records Available.\n");
        return;
    }

    /* Count the records */
    count = count_records(head);

    /* Allocate memory for pointer array */
    arr = (SDB **)malloc(count * sizeof(SDB *));

    if (arr == NULL)
    {
        printf("\nMemory Allocation Failed.\n");
        return;
    }

    /* Store node addresses */
    temp = head;

    for (i = 0; i < count; i++)
    {
        arr[i] = temp;
        temp = temp->next;
    }

    /* Display in reverse order */

    printf("\n");
    printf("=================================================================\n");
    printf("| %-8s | %-25s | %-10s |\n",
           "Roll No",
           "Student Name",
           "Percentage");
    printf("=================================================================\n");

    for (i = count - 1; i >= 0; i--)
    {
        printf("| %-8d | %-25s | %-9.2f%% |\n",
               arr[i]->rollno,
               arr[i]->name,
               arr[i]->percentage);
    }

    printf("=================================================================\n");

    free(arr);
}