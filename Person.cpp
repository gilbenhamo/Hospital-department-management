#include "Person.h"

Person::Person(string fname, string lname, string id):Fname(fname),Lname(lname),Id(id)
{
}

Person::Person(const Person& other):Fname(other.Fname),Lname(other.Lname),Id(other.Id)
{
}

void Person::print() //initlize the memebers
{
	cout << "First name: " << Fname << " ,Last name: " << Lname << endl;
	cout << "ID: " << Id <<endl;
}
