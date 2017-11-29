#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"

/** \brief lee un archivo
 *
 * \param pFile FILE*
 * \param pArrayListEmployee ArrayList*
 * \return int
 *
 */
int parserEmployee(FILE* pFile,ArrayList* pArrayListEmployee)
{
    Employee* empleado;
    char id[50],name[50],lastName[50],age[50],type[50];
    if(pFile != NULL)
        printf("SIIIIIIIIIIIIIIIII \n\n");

    fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,name,lastName,age,type);
    while(!feof(pFile))
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,name,lastName,age,type);
        empleado = employee_new(atoi(id),name,lastName,atoi(age),atoi(type));
        al_add(pArrayListEmployee,empleado);
    }
    fclose(pFile);
    return 0;
}
