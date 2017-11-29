#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"
#include "DataManager.h"

/** \brief crea un nuevo archivo de salida
 *
 * \param list ArrayList*
 * \return int
 *
 */
int dm_dumpEmployeeList(ArrayList* list)
{
    int i;
    FILE *pArchivo;
    pArchivo = fopen("out.csv","w");
    if(pArchivo == NULL)
    {
        printf("No se pudo abrir el archivo\n");
    }
    else
    {
        fprintf(pArchivo,"id,first_name,last_name,age,type\n");
        Employee* auxEmployee;
        for(i=0; i <al_len(list); i++)
        {
            auxEmployee = al_get(list,i);
            fprintf(pArchivo,"%d, %s, %s, %d, %d\n", emp_getID(auxEmployee), emp_getName(auxEmployee),emp_getLastName(auxEmployee),emp_getAge(auxEmployee),emp_getType(auxEmployee));
        }
    }
    fclose(pArchivo);
    printf("\nArchivo guardado con exito\n");
    return 0;
}
