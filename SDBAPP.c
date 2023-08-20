#include <stdio.h>
#include <stdlib.h>
#include "SDB.h"


void SDB_APP()                                                                     //main menu display
{
    uint8 user_choice, i;

    while (SDB_GetUsedSize() < 3)                                                  //to make sure  minimum 3 students
        SDB_AddEntry();                                                            //add minimum 3 student

                                          /*  Component of menu display  */

    printf("To add entry, enter 1\n");
    printf("To get used size in database, enter 2\n");
    printf("To read student data, enter 3\n");
    printf("To get the list of all student IDs, enter 4\n");
    printf("To check is ID is existed, enter 5 \n");
    printf("To delete student data, enter 6\n");
    printf("To check is database is full, enter 7\n");
    printf("To exit enter 0\n");

    printf("Enter Your Choice : ");                                               //ask user to enter what who want do 
    scanf_s("%d", &user_choice);
    printf("\n");
    SDB_action(user_choice);                                                     //call function depending on user choice 
} 

void SDB_action(uint8 choice)                                                    //chose function from menu to be applied
{
    uint32 deleteid;
    uint32 IfIdExist;
    uint32 readid;
    int8 condition;
    uint8 countpointer;
    uint32* listpointer[Max_Student];
    uint8 i;

        switch (choice)
        {
        case(0):                                                                  //to exit from program
            exit(0);
        case(1):                                                                  //to add entry
            if (SDB_AddEntry())                                                   //cheak if adding done 
                printf("Done !\n");
            else                                                                  //warning message if adding fail
                printf("Error ! ,DataBase is full \n");
            break;

        case(2):                                                                   //get used size in database
            printf("Size of DataBase : %d \n", SDB_GetUsedSize());
            break;

        case(3):                                                                   //read student data
            printf("\n Enter The Id Needed To Be Scanned :");
            scanf_s("%d", &readid);                                                //take id that i want know all information about it from user
            if (SDB_ReadEntry(readid))                                             //check if id in database
                printf("\n Found \n");
            else                                               
                printf("Not Found\n");
            break;

        case(4):                                                                   //get the list of all student IDs and number of them
            SDB_GetList(&countpointer, &listpointer);
            printf("\n %d \n", countpointer);
            for (i = 0;i < countpointer;i++)
                printf("%d ", *(listpointer + i));
            printf("\n");
            break;


        case(5):                                                                    //check is ID is existed
            printf("\n Enter The Id Needed To Be Scanned :");
            scanf_s("%d", &IfIdExist);                                              //take id that i want check about it from user
            if (SDB_IsIdExist(IfIdExist))                       
                printf("Found\n");
            else
                printf("Not Found\n");
            break;

        case(6):                                                                    //delete student data
            printf("\n Enter The Id Needed To Be Deleted :");
            scanf_s("%d", &deleteid);                                               //take id that i want delete it from user
            SDB_DeletEntry(deleteid); 
            break;

        case(7):                                                                   //check is database is full
            if (SDB_IsFull())                            
                printf("DataBase is Full\n");
            else
                printf("There Is a place,add more student if you want \n");
            break;

        default: 
            printf("Wrong Entry ! \n");                                             //if user input not on system
        }

        printf(" \n");
        SDB_APP();                                                                 // loop the main menu again after break function
}
