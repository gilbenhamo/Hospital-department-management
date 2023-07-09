#include "Employee.h"
#ifndef NURSE
#define NURSE

class Nurse : public Employee
{
private:
	string department;
	int TrainingAndCourses;
public:
	Nurse(string = "Unknown", string = "Unknown", string = "000000", int = 0, string = "Unknown", int = 0);
	Nurse(const Nurse& other);
	~Nurse();
	void print();
	bool Outstanding();
	void UpdateSal();
	friend istream& operator >> (istream&, Nurse&);
	string getDep() { return department; }
	void setDep(string hosp) { department = hosp; } //update hosp name
};
#endif // !NURSE

