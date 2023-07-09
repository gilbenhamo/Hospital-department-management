#include "Patient.h"

Patient::Patient(string fname, string lname, string id, string dep, int covTest, int Negative):Person(fname,lname,id),department(dep),CovidTests(covTest),NegativeTests(Negative)
{
}

Patient::Patient(const Patient &other) : Person(other.Fname, other.Lname, other.Id), department(other.department), CovidTests(other.CovidTests), NegativeTests(other.NegativeTests)
{
}

Patient::~Patient()
{
}

void Patient::print()
{
	cout << "Patient:\n";
	Person::print();
	cout << "Number of covid-19 tests: " << CovidTests << "  Number of negative tests: " << NegativeTests << endl;
}

void Patient::incTests(bool test) // update patient tests sections
{
	if (test)
		CovidTests++; // if the test is postive update only the amount of tests
	else // update amount of tests and amount of negative tests
	{
		CovidTests++;
		NegativeTests++;
	}
}

istream & operator>>(istream & inp, Patient & obj) // input for patients
{
	cout << "~Enter patient details~\n";
	cout << "First name: ";
	getline(cin, obj.Fname);
	cout << "Enter last name: ";
	getline(cin, obj.Lname);
	cout << "Enter ID: ";
	cin >> obj.Id;
	cout << "Enter number of Covid tests: ";
	cin >> obj.CovidTests;
	do 
	{
	cout << "Enter number of negative tests: ";
	cin >> obj.NegativeTests;
	} while (obj.NegativeTests > obj.CovidTests);
	return inp;
}
