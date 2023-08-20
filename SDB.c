#include <stdio.h>
#include <stdlib.h>

#include "SDB.h"

extern student DataBase[Max_Student];
static uint32 NO_OF_STUDENT = 0;

bool SDB_IsFull()                                                       //determine if database is full
{
    return  NO_OF_STUDENT == Max_Student;
}

uint8 SDB_GetUsedSize()                                                //determine no of records in database
{
    return NO_OF_STUDENT;
}


bool SDB_AddEntry()                                                    //add new student info
{
    student New_Student;                                               //create object of database to add student informations
    if (SDB_IsFull())                                                  //check if database if full
        return false;
    else                                                               //take information of student from user 
    {
        printf("Enter ID Of Student : ");            
        scanf_s("%d", &New_Student.Student_ID);

        printf("Enter Year Of Student : ");
        scanf_s("%d", &New_Student.Student_year);

        printf("Enter ID Of First Course : ");
        scanf_s("%d", &New_Student.Course1_ID);

        printf("Enter Grade Of First Course : ");
        scanf_s("%d", &New_Student.Course1_grade);

        printf("Enter ID Of Second Course : ");
        scanf_s("%d", &New_Student.Course2_ID);

        printf("Enter Grade Of Second Course : ");
        scanf_s("%d", &New_Student.Course2_grade);

        printf("Enter ID Of Third Course : ");
        scanf_s("%d", &New_Student.Course3_ID);

        printf("Enter Grade Of Third Course : ");
        scanf_s("%d", &New_Student.Course3_grade);

        printf("---------------------------------------------\n");

        DataBase[NO_OF_STUDENT] = New_Student;                      //add student to database 
        NO_OF_STUDENT++;                                            //increament the database 

        return true;
    }
}

void SDB_DeletEntry(uint32 id)                                     //delete  student from database
{
    uint32 i, j;
    for (i = 0;i < NO_OF_STUDENT;i++)                              //loop all  id to check if found in database or not 
    {
        if (DataBase[i].Student_ID == id)                          //if found id that user want to delete it
        { 
            for (j = i + 1;j < NO_OF_STUDENT;j++)
            {
                DataBase[j - 1] = DataBase[j];                     //shift students location in database to drop deleted id 
            }       
            NO_OF_STUDENT--;                                       //decrement database after delete student 
            printf("deleted successfully\n");
        }
    }
}



bool SDB_ReadEntry(uint32 id)                                                             //search for student and read student info if found
{
    uint32 i, j;
    for (i = 0;i < NO_OF_STUDENT;i++)                                                     //loop all  id to check if found in database or not 
    {
        if (DataBase[i].Student_ID == id)                                                 // if  found id in database 
        {
            printf("The ID of Student No %d is %d: \n", i + 1, DataBase[i].Student_ID);
            printf("The Year of Student No %d is %d: \n", i, DataBase[i].Student_year);
            printf("The First Course ID is %d: \n", DataBase[i].Course1_ID);
            printf("The Grade Of First Course is %d: \n", DataBase[i].Course1_grade);
            printf("The Second Course ID is %d: \n", DataBase[i].Course2_ID);
            printf("The Grade Of Second Course is %d: \n", DataBase[i].Course2_grade);
            printf("The Third Course ID is %d: \n", DataBase[i].Course3_ID);
            printf("The Grade Of Third Course is %d: \n", DataBase[i].Course3_grade);
            return true;
        }
    }
    return false;
}


void SDB_GetList(uint8* count, uint32* list[Max_Student])                      //get number of student and list all ids
{
    uint32 i;
    *count = NO_OF_STUDENT;
    for (i = 0;i < NO_OF_STUDENT;i++)
    { 
        list[i] = DataBase[i].Student_ID;                                     //make list of ids 
    }
}

bool SDB_IsIdExist(uint32 id)                                                 //check if id exist or not
{
    uint32 i;
    for (i = 0; i < NO_OF_STUDENT; i++)                                       //loop all  id to check if found in database or not 
    {
        if (DataBase[i].Student_ID == id)                                     // if id found in database 
        {
            return true;
        }
    }
    return false;
}
