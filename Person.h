#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

#ifndef PERSON
#define PERSON

class Person
{
protected:
	string Fname;
	string Lname;
	string Id;
public:
	Person(string = "Unknown", string = "Unknown", string = "000000"); //defaults and parametric ctors
	Person(const Person& other);
	virtual ~Person() = 0 {}; // abstract class
	virtual void print();
	string getId() { return Id; }
	
};


#endif // !Person


