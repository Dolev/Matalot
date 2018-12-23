#include "iostream"
#include "Employee.h"
#include <string.h>
#include <assert.h>
//@auter Dolev Hindy
//
using namespace std;
Employee::Employee(char a_emp_name[],long a_emp_id, float a_emp_salary)
{
strncpy_s(m_sName, a_emp_name,MAX_NAME_SIZE);
m_lId = a_emp_id;
m_fSalary = a_emp_salary;
}
void Employee::ShowEmployee()
{
cout << "Employee: " << m_sName << endl;
cout << "Id: " << m_lId << endl;
cout << "Salary: " << m_fSalary << endl;
}
void Employee::SetSalary(float new_salary)
{
assert(new_salary>0);
m_fSalary = new_salary;
}
long Employee::GetId()
{
return m_lId;
}
float Employee::GetSalary()
{
return m_fSalary;
}
void Employee::Bonus(Employee *Emp)
{
m_fSalary += Emp->m_fSalary;
}
