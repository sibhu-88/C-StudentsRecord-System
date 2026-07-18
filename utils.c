/*
 *=========================================================
 *  Project : Student Record Management System
 *  File    : utils.c
 *  Author  : Your Name
 *=========================================================
 */

#include "header.h"

/*---------------------------------------------------------
                Clear Terminal Screen
---------------------------------------------------------*/
void clear_screen(void)
{
    printf("\033[2J\033[H");
}

/*---------------------------------------------------------
                Pause Screen
---------------------------------------------------------*/
void pause_screen(void)
{
    printf("\nPress Enter to continue...");
    while (getchar() != '\n');
    getchar();
}

/*---------------------------------------------------------
                Print Table Header
---------------------------------------------------------*/
void print_table_header(void)
{
    printf("\n");
    printf("\t+---------+------------------------------+------------+\n");
    printf("\t| Roll No | Name                         | Percentage |\n");
    printf("\t+---------+------------------------------+------------+\n");
}

/*---------------------------------------------------------
                Print Table Footer
---------------------------------------------------------*/
void print_table_footer(void)
{
    printf("\t+---------+------------------------------+------------+\n");
}

/*---------------------------------------------------------
            Count Number of Records
---------------------------------------------------------*/
int count_records(SDB *head)
{
    int count = 0;

    while (head != NULL)
    {
        count++;
        head = head->next;
    }

    return count;
}

/*---------------------------------------------------------
            Search by Roll Number
---------------------------------------------------------*/
SDB *search_by_rollno(SDB *head, int roll)
{
    while (head != NULL)
    {
        if (head->rollno == roll)
            return head;

        head = head->next;
    }

    return NULL;
}

/*---------------------------------------------------------
            Search by Name
---------------------------------------------------------*/
SDB *search_by_name(SDB *head, char name[])
{
    while (head != NULL)
    {
        if (strcasecmp(head->name, name) == 0)
            return head;

        head = head->next;
    }

    return NULL;
}

/*---------------------------------------------------------
            Search by Percentage
---------------------------------------------------------*/
SDB *search_by_percentage(SDB *head, float percentage)
{
    while (head != NULL)
    {
        if (head->percentage == percentage)
            return head;

        head = head->next;
    }

    return NULL;
}

/*---------------------------------------------------------
            Exit Program
---------------------------------------------------------*/
void exit_program(SDB **head)
{
    char choice;

    while (1)
    {
        clear_screen();

        display_exit_menu();

        printf("\nEnter Your Choice : ");
        scanf(" %c", &choice);

        choice = tolower(choice);

        switch (choice)
        {
            case 's':

                save_records(*head);
                printf("\nRecords Saved Successfully.\n");
                printf("Thank You For Using Student Record Management System.\n");

                exit(EXIT_SUCCESS);

            case 'e':
                printf("\nExiting Without Saving...\n");
                printf("Thank You For Using Student Record Management System.\n");

                exit(EXIT_SUCCESS);

            case 'c':

                return;

            default:

                printf("\nInvalid Choice!\n");
                pause_screen();
        }
    }
}

int generate_rollno(SDB *head)
{
    int max = 100;

    while (head != NULL)
    {
        if (head->rollno > max)
            max = head->rollno;

        head = head->next;
    }

    return max + 1;
}