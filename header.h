#ifndef HEADER_H
#define HEADER_H

/*====================================================
                Header Files
====================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

/*====================================================
                Macros
====================================================*/
#define NAME_SIZE       50
#define FILE_NAME       "student.txt"

/*====================================================
            Student Structure
====================================================*/
typedef struct student
{
    int rollno;
    char name[NAME_SIZE];
    float percentage;
    struct student *next;
}SDB;

/*====================================================
            Utility Functions
====================================================*/
void clear_screen(void);
void pause_screen(void);
void print_table_header(void);
void print_table_footer(void);

/*====================================================
            Menu Functions
====================================================*/
void display_main_menu(void);
void display_delete_menu(void);
void display_modify_menu(void);
void display_modify_options_menu(void);
void display_sort_menu(void);
void display_exit_menu(void);

/*====================================================
            File Handling
====================================================*/
void read_records_from_file(SDB **head);
void save_records(SDB *head);

/*====================================================
            Add Record
====================================================*/
void add_new_record(SDB **head);

/*====================================================
            Delete Record
====================================================*/
void delete_record(SDB **head);
void delete_record_by_rollno(SDB **head);
void delete_record_by_name(SDB **head);

/*====================================================
            Modify Record
====================================================*/
void modify_record(SDB **head);
void modify_by_rollno(SDB *head);
void modify_by_name(SDB *head);
void modify_record_options(SDB *record);

/*====================================================
            Display Record
====================================================*/
void display_student_list(SDB *head);

/*====================================================
            Search Functions
====================================================*/
SDB *search_by_rollno(SDB *head,int roll);
SDB *search_by_name(SDB *head,char name[]);

/*====================================================
            Sorting
====================================================*/
void sort_student_list(SDB *head);
void sort_by_name(SDB **arr,int n);
void sort_by_percentage(SDB **arr,int n);
void sort_by_rollno(SDB **arr,int n);
void print_sorted_records(SDB **arr,int n);

/*====================================================
            Reverse
====================================================*/
void reverse_student_list(SDB *head);

/*====================================================
            Miscellaneous
====================================================*/
int count_records(SDB *head);
void exit_program(SDB **head);
int generate_rollno(SDB *head);

#endif