#include "Employee.h"

Employee::Employee(string fname, string lname, string id, int sen):Person(fname,lname,id),Seniority(sen),Salary(BASIS_SAL)
{
}

Employee::Employee(const Employee & other) : Person(other.Fname, other.Lname, other.Id),Seniority(other.Seniority),Salary(BASIS_SAL)
{
}

Employee::~Employee()
{
}

void Employee::print()
{
	Person::print();
	cout << "Seniority:" << Seniority << ", Salary: " << Salary << endl;
}

bool Employee::Outstanding() //empty body only for next inheritance
{
	return false;
}


