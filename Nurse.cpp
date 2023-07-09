#include "Nurse.h"

Nurse::Nurse(string fname, string lname, string id, int sen, string dep, int train):Employee(fname,lname,id,sen),department(dep),TrainingAndCourses(train)
{
	UpdateSal(); //update salary section in emoployee
}

Nurse::Nurse(const Nurse & other):Employee(other.Fname,other.Lname,other.Id,other.getSeniority()),department(other.department),TrainingAndCourses(other.TrainingAndCourses)
{
	UpdateSal(); //update the salary in employee
}

Nurse::~Nurse()
{
}

void Nurse::print()
{
	cout << "Nurse:\n";
	Employee::print();
	cout << "Department: " << department << ", Training and courses: " << TrainingAndCourses << endl;
}

bool Nurse::Outstanding()
{
	if (TrainingAndCourses >= getSeniority()) //check if the nurse is outstanding nurse
		return true;
	return false;
}

void Nurse::UpdateSal()
{
	setSalary(BASIS_SAL + (TrainingAndCourses * 50)); // update the salary
}

istream & operator>>(istream& inp, Nurse& obj) // input for nurse
{
	cout << "~Enter Nurse details~\n";
	cout << "First name: ";
	getline(cin, obj.Fname);
	cout << "Enter last name: ";
	getline(cin, obj.Lname);
	cout << "Enter ID: ";
	cin >> obj.Id;
	cout << "Enter Seniority: ";
	cin >> obj.Seniority;
	cout << "Enter number training and courses amount: ";
	cin >> obj.TrainingAndCourses;
	obj.UpdateSal();
	return inp;
}
