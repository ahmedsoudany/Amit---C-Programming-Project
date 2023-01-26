#ifndef C_PROJECT_H_INCLUDED
#define C_PROJECT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define M_data 10  // maximum number of the database
#define M_grade 100 // maximum grade allowed


typedef unsigned int unit8;

unit8 no_of_entries;  // variable to store the number of entries entered by the user
unit8 found ;         // variable to check if the entered id found or not
unit8 d_element;      //variable to store the no of the entry in the structure to be deleted
// Structure that hold the parameters of the  database
struct SimpleDb
{
    unit8 id;
    unit8 year;
    unit8 c_1_id[100];
    unit8 c_1_grd;
    unit8 c_2_id[100];
    unit8 c_2_grd;
    unit8 c_3_id[100];
    unit8 c_3_grd;
};

struct SimpleDb *SDB;



bool SDB_IsFull(void); //Function to check if the database is full


unit8 SDB_GetUsedSize(void); //Function used to get the no of the enteries


bool SDB_AddEntry(unit8 id, unit8 year, unit8* subjects, unit8* grades); // Function to add any entry to the database


void SDB_DeletEntry(unit8 id); //Funtion to delete an entry from the database using id


bool SDB_ReadEntry(unit8 id, unit8* year, unit8* subjects, unit8* grades); // Function to read an entry from the database by using id


void SDB_GetList(unit8* count, unit8* list); //function to print the database ids and to return pointer to the list of ids and another one to the current no of entries currently in the data base


bool SDB_IsIdExist(unit8 ID); //function to check if an id exist or not



#endif // C_PROJECT_H_INCLUDED
