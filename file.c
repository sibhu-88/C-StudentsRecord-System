/*
 *=========================================================
 *  Project : Student Record Management System
 *  File    : file.c
 *  Author  : Prabhu
 *=========================================================
 */

#include "header.h"

/*---------------------------------------------------------
            Read Records From File
---------------------------------------------------------*/
void read_records_from_file(SDB **head)
{
    FILE *fp;
    SDB *newnode, *last = NULL;

    fp = fopen(FILE_NAME, "r");

    if (fp == NULL)
    {
        printf("\n%s not found.\n", FILE_NAME);
        printf("A new database will be created after saving.\n");
        return;
    }

    while (1)
    {
        newnode = (SDB *)malloc(sizeof(SDB));

        if (newnode == NULL)
        {
            printf("\nMemory Allocation Failed!\n");
            fclose(fp);
            return;
        }

        if (fscanf(fp,
                   "%d %49s %f",
                   &newnode->rollno,
                   newnode->name,
                   &newnode->percentage) != 3)
        {
            free(newnode);
            break;
        }

        newnode->next = NULL;

        if (*head == NULL)
        {
            *head = newnode;
            last = newnode;
        }
        else
        {
            last->next = newnode;
            last = newnode;
        }
    }

    fclose(fp);
}

/*---------------------------------------------------------
                Save Records To File
---------------------------------------------------------*/
void save_records(SDB *head)
{
    FILE *fp;

    fp = fopen(FILE_NAME, "w");

    if (fp == NULL)
    {
        printf("\nUnable to Open %s\n", FILE_NAME);
        return;
    }

    while (head != NULL)
    {
        fprintf(fp,
                "%d %s %.2f\n",
                head->rollno,
                head->name,
                head->percentage);

        head = head->next;
    }

    fclose(fp);

    printf("\nRecords Saved Successfully.\n");
}
