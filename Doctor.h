#include "Employee.h"
#ifndef DOCTOR
#define DOCTOR
#define BONUS 2000
class Doctor : public Employee
{
private:
	string department;
	bool professor;
	int PosEval;
public:
	Doctor(string = "Unknown", string = "Unknown", string = "000000", int = 0, string = "Unknown", int = 0,int=0);
	Doctor(const Doctor& other);
	~Doctor();
	bool Outstanding();
	void print();
	void UpdateSal();
	friend istream& operator >> (istream&, Doctor&);
	string getDep() { return department; }
	void setDep(string hosp) { department = hosp; } //update hosp name
};
#endif // !DOCTOR

