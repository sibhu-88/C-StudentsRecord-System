/*
 *=========================================================
 *  Project : Student Record Management System
 *  File    : menu.c
 *  Author  : Prabhu
 *=========================================================
 */

#include "header.h"

/*---------------------------------------------------------
                    Main Menu
---------------------------------------------------------*/
void display_main_menu(void)
{
    printf("\n");
    printf("\t********************************************************\n");
    printf("\t*          STUDENT RECORD MANAGEMENT SYSTEM            *\n");
    printf("\t********************************************************\n");
    printf("\t* [A] Add New Student Record                           *\n");
    printf("\t* [D] Delete Student Record                            *\n");
    printf("\t* [M] Modify Student Record                            *\n");
    printf("\t* [S] Show All Student Records                         *\n");
    printf("\t* [T] Sort Student Records                             *\n");
    printf("\t* [R] Reverse Student Records                          *\n");
    printf("\t* [V] Save Records                                     *\n");
    printf("\t* [E] Exit Program                                     *\n");
    printf("\t********************************************************\n");
    printf("\tEnter Your Choice : ");
}

/*---------------------------------------------------------
                  Delete Menu
---------------------------------------------------------*/
void display_delete_menu(void)
{
    printf("\n");
    printf("\t********************************************************\n");
    printf("\t*              DELETE STUDENT RECORD                  *\n");
    printf("\t********************************************************\n");
    printf("\t* [R] Delete by Roll Number                           *\n");
    printf("\t* [N] Delete by Student Name                          *\n");
    printf("\t* [B] Back to Main Menu                               *\n");
    printf("\t********************************************************\n");
    printf("\tEnter Your Choice : ");
}

/*---------------------------------------------------------
                  Modify Menu
---------------------------------------------------------*/
void display_modify_menu(void)
{
    printf("\n");
    printf("\t********************************************************\n");
    printf("\t*              MODIFY STUDENT RECORD                  *\n");
    printf("\t********************************************************\n");
    printf("\t* [R] Search by Roll Number                           *\n");
    printf("\t* [N] Search by Student Name                          *\n");
    printf("\t* [B] Back to Main Menu                               *\n");
    printf("\t********************************************************\n");
    printf("\tEnter Your Choice : ");
}

/*---------------------------------------------------------
              Modify Options Menu
---------------------------------------------------------*/
void display_modify_options_menu(void)
{
    printf("\n");
    printf("\t********************************************************\n");
    printf("\t*          MODIFY STUDENT RECORD OPTIONS              *\n");
    printf("\t********************************************************\n");
    printf("\t* [N] Modify Student Name                             *\n");
    printf("\t* [P] Modify Percentage                               *\n");
    printf("\t* [B] Back                                            *\n");
    printf("\t********************************************************\n");
    printf("\tEnter Your Choice : ");
}

/*---------------------------------------------------------
                    Sort Menu
---------------------------------------------------------*/
void display_sort_menu(void)
{
    printf("\n");
    printf("\t********************************************************\n");
    printf("\t*               SORT STUDENT RECORDS                  *\n");
    printf("\t********************************************************\n");
    printf("\t* [N] Sort by Student Name                            *\n");
    printf("\t* [P] Sort by Percentage                              *\n");
    printf("\t* [B] Back to Main Menu                               *\n");
    printf("\t********************************************************\n");
    printf("\tEnter Your Choice : ");
}

/*---------------------------------------------------------
                    Exit Menu
---------------------------------------------------------*/
void display_exit_menu(void)
{
    printf("\n");
    printf("\t********************************************************\n");
    printf("\t*                EXIT CONFIRMATION                    *\n");
    printf("\t********************************************************\n");
    printf("\t* [S] Save Changes and Exit                           *\n");
    printf("\t* [E] Exit Without Saving                             *\n");
    printf("\t* [C] Cancel                                          *\n");
    printf("\t********************************************************\n");
    printf("\tEnter Your Choice : ");
}