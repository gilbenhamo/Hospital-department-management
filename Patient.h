#include "Person.h"
#ifndef PATIENT
#define PATIENT

class Patient : public Person
{
	string department;
	int CovidTests;
	int NegativeTests;
public:
	Patient(string = "Unknown", string = "Unknown", string = "000000", string = "Unkown", int = 0, int = 0);
	Patient(const Patient& other);
	~Patient();
	int getNegative() { return NegativeTests; }
	void print();
	string getId() { return Id; }
	string getDep() { return department; }
	friend istream& operator >> (istream& inp, Patient& obj);
	void setDep(string hosp) { department = hosp; } //update hosp name
	void incTests(bool test);

};
#endif // !PATIENT
