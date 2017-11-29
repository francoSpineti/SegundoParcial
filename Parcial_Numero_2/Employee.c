#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Employee.h"

/** \brief crea un nuevo empleado
 *
 * \param id int
 * \param name char*
 * \param lastName char*
 * \param age int
 * \param type int
 * \return Employee*
 *
 */
Employee* employee_new(int id,char* name,char* lastName,int age, int type)
{
    Employee* employee = malloc(sizeof(Employee));
    emp_setID(employee,id);
    emp_setName(employee,name);
    emp_setLastName(employee,lastName);
    emp_setAge(employee,age);
    emp_setType(employee,type);

    return employee;
}

/** \brief elimina el empleado
 *
 * \param this Employee*
 * \return void
 *
 */
void employee_delete(Employee* this)
{
    free(this);
}

/** \brief muestra todos los empleados
 *
 * \param this Employee*
 * \return void
 *
 */
void employee_print(void* this)
{
    Employee* aux = (Employee*) this;
    printf("\nID: %d \n -NAME: %s \n -LASTNAME: %s \n -AGE: %d \n -TYPE: %d \n",emp_getID(aux),emp_getName(aux),emp_getLastName(aux),emp_getAge(aux),emp_getType(aux));
}

/** \brief filtra si el empleado posee la edad mayor a 30 y el type igual a  EMPLOYEE_TYPE_PROGRAMMER
 *
 * \param item void*
 * \return int
 *
 */
int employee_filterEmployee(void* item)
{
     if(((Employee*)item)->age >= 30 && ((Employee*)item)->type == EMPLOYEE_TYPE_PROGRAMMER)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/***************************** GETS AND SETS ************************************/

/** \brief setea el name
 *
 * \param this Employee*
 * \param name char*
 * \return int
 */
int emp_setName(Employee* this,char* name)
{
    strcpy(this->name,name);
    return 0;
}

/** \brief retorna el name
 *
 * \param this Employee*
 * \return char*
 */
char* emp_getName(Employee* this)
{
    return this->name;
}

/** \brief setea el lastName
 *
 * \param this Employee*
 * \param name char*
 * \return int
 */
int emp_setLastName(Employee* this,char* lastName)
{
    strcpy(this->lastName,lastName);
    return 0;
}

/** \brief retorna el lastName
 *
 * \param this Employee*
 * \return char*
 */
char* emp_getLastName(Employee* this)
{
    return this->lastName;
}

/** \brief setea el id
 *
 * \param this Employee*
 * \param id int
 * \return int
 *
 */
int emp_setID(Employee* this,int id)
{
    this->id = id;
    return 0;
}

/** \brief retorna el id
 *
 * \param this Employee*
 * \return int
 *
 */
int emp_getID(Employee* this)
{
    return this->id;
}

/** \brief setea el age
 *
 * \param this Employee*
 * \param age int
 * \return int
 *
 */
int emp_setAge(Employee* this,int age)
{
    this->age = age;
    return 0;
}

/** \brief retorna el age
 *
 * \param this Employee*
 * \return int
 *
 */
int emp_getAge(Employee* this)
{
    return this->age;
}


/** \brief setea el type
 *
 * \param this Employee*
 * \param type int
 * \return int
 *
 */
int emp_setType(Employee* this,int type)
{
    this->type = type;
    return 0;
}

/** \brief retorna el type
 *
 * \param this Employee*
 * \return int
 *
 */
int emp_getType(Employee* this)
{
    return this->type;
}

/**************************************** FIND'S ************************************************/

/** \brief busca el empleado por id
 *
 * \param pArrayEmployee ArrayList*
 * \param id int
 * \return Employee*
 *
 */
Employee* emp_findById(ArrayList* pArrayEmployee, int id)
{
    int i;
    Employee* auxEmployee;
    void* retorno=NULL;

    for(i=0;i<al_len(pArrayEmployee);i++)
    {
        auxEmployee = al_get(pArrayEmployee,i);
        if(id == emp_getID(auxEmployee))
        {
            retorno = auxEmployee;
        }
    }
    return retorno;
}



