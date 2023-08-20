#ifndef SDB_H_INCLUDED
#define SDB_H_INCLUDED
#include "STD.h"                
 
#define Max_Student 10                   //to limit database


typedef struct SimpleDb                  //information for each student (structure of database)
{
	uint32 Student_ID;
	uint32 Student_year;
	uint32 Course1_ID;
	uint32 Course1_grade;
	uint32 Course2_ID;
	uint32 Course2_grade;
	uint32 Course3_ID;
	uint32 Course3_grade;
} student;

student DataBase[Max_Student];          //object of database 

/*  definition of functions   */

bool SDB_IsFull();
uint8 SDB_GetUsedSize();
bool SDB_AddEntry();
void SDB_DeletEntry(uint32 id);
bool SDB_ReadEntry(uint32 id);
void SDB_GetList(uint8* count, uint32* list[Max_Student]);
bool SDB_IsIdExist(uint32 id);

void SDB_APP();
void SDB_action(uint8 choice);


#endif