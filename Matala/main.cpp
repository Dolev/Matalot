#include "iostream"
#include <conio.h>
#include <stdio.h>
#include "Employee.h"
using namespace std;
void main()
{
Employee worker[] = { Employee("Sami",38764739 ,1000),
Employee("Shimon",3898481,10000) };
Employee *emp1 = new Employee("Shali", 38533170, 18000);
Employee *emp2 = NULL;
worker[0].ShowEmployee();
worker[0].SetSalary(10000);
worker[0].ShowEmployee();
emp1->ShowEmployee();
emp2 = &worker[1];
emp2->Bonus(emp1);
worker[1].ShowEmployee();
worker[1].ShowEmployee();
_getch();
}
