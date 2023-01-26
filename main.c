#include <stdio.h>
#include <stdlib.h>
#include "C project.h"


int main()
{


            SDB = (struct SimpleDb*)malloc(no_of_entries + 2 * sizeof(struct SimpleDb));


            unit8 id, year, *subjects, *grades, *year_r, *count , *list;
            SDB_GetUsedSize();

            unit8 y = SDB_AddEntry( id,  year, &subjects,& grades);

            printf("%d\n\n",y);

            SDB_ReadEntry( id, &year_r,&subjects,&grades);

            SDB_DeletEntry(id);



            SDB_GetList( &count, &list);

            int k = SDB_IsIdExist(id);
              printf("%d\n\n",k);






            int u = SDB_IsFull();
              printf("%d",u);

              free(SDB);
}
