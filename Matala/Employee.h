#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_
#define MAX_NAME_SIZE 128
class Employee
{
public:
//constructor
Employee(char a_emp_name[], long a_emp_id, float a_emp_salary);
void SetSalary(float a_new_salary);
void ShowEmployee();
void Bonus(Employee*);
long GetId();
float GetSalary();
private:
char m_sName[MAX_NAME_SIZE];
long m_lId;
float m_fSalary;
};
#endif
