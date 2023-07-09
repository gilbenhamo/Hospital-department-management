#include "Doctor.h"
#define NAME_SIZE 25

Doctor::Doctor(string fname, string lname, string id, int sen, string dep, int prof, int eval):Employee(fname,lname,id,sen),department(dep),professor(prof),PosEval(eval)
{
	UpdateSal(); //update salary section in employee
}

Doctor::Doctor(const Doctor& other) :Employee(other.Fname, other.Lname, other.Id, other.getSeniority()),department(other.department), professor(other.professor), PosEval(other.PosEval)
{
	UpdateSal(); //update the salary section in employee
}

Doctor::~Doctor()
{
}

bool Doctor::Outstanding()
{
	if (PosEval > 10) //check if the positive evaluation is bigger than 10
		return true;
	return false;
}

void Doctor::print() // print doctor pattern
{
	cout << "Doctor:\n";
	Employee::print();
	cout << "Department: " << department << endl << "Professor: ";
	if (professor)
		cout << "YES\n";
	else
		cout << "NO\n";
	cout << "Number of positive evaluation: " << PosEval << endl;
}

void Doctor::UpdateSal()
{
	if (professor) // check if the doctor is professor to know how to calculate the salary
		setSalary(BASIS_SAL + (200 * getSeniority() + 50 * PosEval) + BONUS);
	else
		setSalary(BASIS_SAL + (200 * getSeniority() + 50 * PosEval));
}

istream& operator>>(istream& inp, Doctor& obj) //doctor input
{
	cout << "~Enter Doctor details~\n";
	cout << "First name: ";
	getline(cin,obj.Fname);
	cout << "Enter last name: ";
	getline(cin,obj.Lname);
	cout << "Enter ID: ";
	cin >> obj.Id;
	cout << "Enter Seniority: ";
	cin >> obj.Seniority;
	cout << "Professor? (1-yes, 0-no):  ";
	cin >> obj.professor;
	cout << "Enter number amount of positive evaluations: ";
	cin >> obj.PosEval;
	obj.UpdateSal();
	return inp;
}
