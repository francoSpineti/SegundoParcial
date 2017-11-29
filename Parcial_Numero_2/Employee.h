#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H

#define EMPLOYEE_TYPE_ARCHITECT    0
#define EMPLOYEE_TYPE_MANAGER      1
#define EMPLOYEE_TYPE_DESIGNER     2
#define EMPLOYEE_TYPE_JUNIOR       3
#define EMPLOYEE_TYPE_PROGRAMMER   4

struct
{
    int id;
    char name[51];
    char lastName[51];
    int age;
    int type;
}typedef Employee;

int employee_filterEmployee(void* item);

void employee_print(void* this);

Employee* employee_new(int id,char* name,char* lastName,int age, int type);

void employee_delete(Employee* this);

int emp_setName(Employee*,char* name);
char* emp_getName(Employee* this);

int emp_setLastName(Employee*,char* lastName);
char* emp_getLastName(Employee* this);

int emp_setID(Employee* this,int id);
int emp_getID(Employee* this);

int emp_setAge(Employee* this,int age);
int emp_getAge(Employee* this);

int emp_setType(Employee* this,int type);
int emp_getType(Employee* this);

Employee* emp_findById(ArrayList*, int id);

Employee* emp_findByAge(ArrayList*, int age);

Employee* emp_findByType(ArrayList*, int type);

#endif // _EMPLOYEE_H



