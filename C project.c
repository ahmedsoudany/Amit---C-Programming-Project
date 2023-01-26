#include "C project.h"


bool SDB_IsFull(void)
{
    //Check if the no of entries is equal to the max. allowed
    if (no_of_entries == 10)
    {
          printf("The database is full!!\n");
          return 1;
    }
    else
    {
        printf("The database is not yet full!!\n");
         return 0;
    }

}

unit8 SDB_GetUsedSize(void)
{

    s_again:
        // scanning the no of entries
    printf("Please enter the number of entries: ");
    scanf("%d",&no_of_entries);
    if(no_of_entries  > M_data)
    {
            printf("Invalid no of entries maximum allowed entries = 10\n");
            goto s_again;  //If the entered entries more than 10 to ask the user to enter again

    }
    else
    return no_of_entries; //return the no of entries
}

bool SDB_AddEntry(unit8 id, unit8 year, unit8* subjects, unit8* grades)
{


    unit8 new_entry = 0; // variable to count how many entries sucesfully entried

    int i;
    // for loop to enter the database information
    for ( i = 0 ; i < no_of_entries ; i++)
    {
        printf("Student no[%d]: \n",i+1);


        printf("Enter student no.[%d] id: ",i+1);
        scanf("%d",&((SDB) + i)->id);
        printf("Enter student no.[%d] year: ",i+1);
        scanf("%d",&((SDB) + i)->year);


        printf("Enter student no.[%d] First subject: ",i+1);
        scanf("%s",((SDB) + i)->c_1_id);
        f_again:
        printf("Enter student no.[%d] First grade: ",i+1);
        scanf("%d",&((SDB) + i)->c_1_grd);

        //Condition to check if the grade is between the range of 0 and 100
        if(((SDB) + i)->c_1_grd < 0 || ((SDB) + i)->c_1_grd > M_grade)
        {
            printf("Invalid grade maximum allowed grade = 100\n");
            goto f_again;

        }

        printf("Enter student no.[%d] Second subject: ",i+1);
        scanf("%s",((SDB) + i)->c_2_id);
        s_again:
        printf("Enter student no.[%d] Second grade: ",i+1);
        scanf("%d",&((SDB) + i)->c_2_grd);

         //Condition to check if the grade is between the range of 0 and 100
        if(((SDB) + i)->c_2_grd < 0 || ((SDB) + i)->c_2_grd > M_grade)
        {
            printf("Invalid grade maximum allowed grade = 100\n");
            goto s_again;

        }

        printf("Enter student no.[%d] Third subject: ",i+1);
        scanf("%s",((SDB) + i)->c_3_id);
        t_again:
        printf("Enter student no.[%d] Third grade: ",i+1);
        scanf("%d",&((SDB) + i)->c_3_grd);

        //Condition to check if the grade is between the range of 0 and 100
        if(((SDB) + i)->c_3_grd < 0 || ((SDB) + i)->c_3_grd > M_grade)
        {
            printf("Invalid grade maximum allowed grade = 100\n");
            goto t_again;

      }

       new_entry++;


    }
    if(new_entry == no_of_entries) //Condition to check the used entered entries = actual entered
            return 1;
            else
            return 0;


    printf("\n\n");



}


void SDB_DeletEntry(unit8 id)
{
      unit8 e_delete; // varaiable to store the no of id to delete it
      char null [10]= {"\0"};

      d_again:


      printf("\nEnter the ID to delete it from entry: ");
      scanf("%d",&e_delete);




      int i;

      for (i = 0 ; i < no_of_entries; i++)
      {
          //checks if the id of the entry exist in the database
          if(e_delete == ((SDB) + i)->id)
          {
              d_element = i;
              found = true;
            break;


          }
      }


      // for loop to remove the id from the database

          for (i = d_element ; i < no_of_entries - 1  ; i++)
          {
                 *((SDB)+i)=*((SDB)+i+1);

          }

              no_of_entries--;


      //condition to check if the user entered a wrong id and wants to enter another one
          if(found != true)
          {
           printf("ID does not exist in the database!!\n");
           printf("If you want to entry the id again to delete it press (y) or ppress anything else to exit:\n");


          char d;
          fflush(stdin);
          scanf("%c",&d);

          if(d == 'y')

          goto d_again;

         }



       int j;
       // for loop to check if the id is deleted from the database
       for ( j = 0 ; j < no_of_entries ; j++)
        {


        printf("Student no.[%d] id: %d\n",j+1,((SDB) + j)->id);
        printf("Student no.[%d] year: %d\n",j+1,((SDB) + j)->year);

        printf("Student no.[%d] First subject: %s\n",j+1,((SDB) + j)->c_1_id);

        printf("Student no.[%d] Second subject: %s\n",j+1,((SDB) + j)->c_2_id);
        printf("Student no.[%d] Third subject: %s\n",j+1,((SDB) + j)->c_3_id);

        printf("Student no.[%d] First grade: %d\n",j+1,((SDB) + j)->c_1_grd);
        printf("Student no.[%d] Second grade: %d\n",j+1,((SDB) + j)->c_2_grd);
        printf("Student no.[%d] Third grade: %d\n",j+1,((SDB) + j)->c_3_grd);

       }

}

bool SDB_ReadEntry(unit8 id, unit8* year, unit8* subjects, unit8* grades)
{


    unit8 find_entry; //variable to store the id of the student to read his information

    r_again:
    printf("Enter the Student id to read the entry: ");
    scanf("%d",&find_entry);


     int j;
     //for loop to find the id in the database
    for ( j = 0 ; j < no_of_entries ; j++)
    {
        // condition to check if the id exist in the database
        if(find_entry == ((SDB) + j)->id)
        {
            printf("ID founded:\n");
            printf("Student no.[%d] year: %d\n",j+1,((SDB) + j)->id);

        printf("Student no.[%d] year: %d\n",j+1,((SDB) + j)->year);

        printf("Student no.[%d] first subject: %s\n",j+1,((SDB) + j)->c_1_id);

        printf("Student no.[%d] Second subject: %s\n",j+1,((SDB) + j)->c_2_id);
        printf("Student no.[%d] Third subject: %s\n",j+1,((SDB) + j)->c_3_id);

        printf("Student no.[%d] first grade: %d\n",j+1,((SDB) + j)->c_1_grd);
        printf("Student no.[%d] Second grade: %d\n",j+1,((SDB) + j)->c_2_grd);
        printf("Student no.[%d] Third grade: %d\n",j+1,((SDB) + j)->c_3_grd);

        found = true; // if id is exit set found to true
         break;

        }


    }
    if(found != true) //Condition to ask the user to enter the id if he wants again to read it
    {
        printf("Not found in the database!!\n");
        printf("If you want to try again press (y) if not press anything:\n");
         char r;

          fflush(stdin);
          scanf("%c",&r);

          if(r == 'y')
          goto r_again;


    }



}

void SDB_GetList(unit8* count, unit8* list)
{
    int i;
    int c = 0; // initializing the counter to zero

    // for loop to get the list exist i the database
    for(i = 0 ; i < no_of_entries ; i++)
    {
        printf("\n");

        printf("Student no[%d] id: %d\n",i+1,((SDB) + i)->id);
        c++;
    }

    count = &c;
    list = &((SDB) + 0)->id;

    printf("\nThe counter is equal to: %d\n",*count);

}


bool SDB_IsIdExist(unit8 ID)
{
    unit8 id_exist;// variable to store the id to find it in the database

    printf("Enter the id you want to find: ");
    scanf("%d",&id_exist);

    int i;
    //for loop to find the entered id
    for (i = 0 ; i < no_of_entries ; i++)
    {
        //checks if the id exist in the data base
        if(id_exist == ((SDB) + i)->id)
        {
            printf("ID exist!!\n");
            return 1;

        }

    }
    printf("ID not found!!\n");
    return 0;


}

