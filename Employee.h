#ifndef EMPLOYEE
#define EMPLOYEE
#define BASIS_SAL 6500

#include "Person.h"

class Employee : public Person
{
protected:
	int Seniority;
	int Salary; // common salary thats update in each class specs
public:
	Employee(string = "Unknown", string = "Unknown", string = "000000", int = 0);
	Employee(const Employee& other);
	virtual ~Employee();
	virtual void print();
	bool virtual Outstanding();
	int getSalary()const { return Salary; }
	void setSalary(int sal) { Salary = sal; } //update salary
	int getSeniority()const { return Seniority; }
};
#endif // !EMPLOYEE

