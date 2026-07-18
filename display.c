/*
 *=========================================================
 *  Project : Student Record Management System
 *  File    : display.c
 *  Author  : Prabhu
 *=========================================================
 */

#include "header.h"

/*---------------------------------------------------------
            Display All Student Records
---------------------------------------------------------*/
void display_student_list(SDB *head)
{
    int count = 0;

    if (head == NULL)
    {
        printf("\n=========================================\n");
        printf("      NO STUDENT RECORDS AVAILABLE\n");
        printf("=========================================\n");
        return;
    }

    printf("\n");
    printf("=================================================================\n");
    printf("| %-8s | %-25s | %-10s |\n",
            "Roll No",
            "Student Name",
            "Percentage");
    printf("=================================================================\n");

    while (head != NULL)
    {
        printf("| %-8d | %-25s | %-9.2f%% |\n",
                head->rollno,
                head->name,
                head->percentage);

        head = head->next;
        count++;
    }

    printf("=================================================================\n");
    printf("Total Records : %d\n", count);
}