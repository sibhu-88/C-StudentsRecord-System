/*
 *=========================================================
 *  Project : Student Record Management System
 *  File    : main.c
 *  Author  : prabhu
 *=========================================================
 */

#include "header.h"

int main(void)
{
    char choice;
    SDB *head = NULL;

    /* Load student records from file */
    read_records_from_file(&head);

    while (1)
    {
        clear_screen();

        display_main_menu();

        //printf("\nEnter Your Choice : ");
        scanf(" %c", &choice);

        choice = tolower(choice);

        switch (choice)
        {
            case 'a':
                add_new_record(&head);
                break;

            case 'd':
                delete_record(&head);
                break;

            case 'm':
                modify_record(&head);
                break;

            case 's':
                display_student_list(head);
                break;

            case 't':
                sort_student_list(head);
                break;

            case 'r':
                reverse_student_list(head);
                break;

            case 'v':
                save_records(head);
                printf("\nRecords saved successfully.\n");
                break;

            case 'e':
                exit_program(&head);
                break;

            default:
                printf("\nInvalid Choice!\n");
                printf("Please Enter a Valid Option.\n");
                break;
        }

        pause_screen();
    }

    return 0;
}