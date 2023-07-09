#ifndef COVIDCRISIS
#define COVIDCRISIS
#include "CovidDep.h"

class CovidCrisis
{
private:
	Patient** patients;
	CovidDep** departments;
	Employee** employees;
	int patSize;
	int depSize;
	int empSize;
//---------methods----------//
	void printOptions();
	bool searchID(string id);
	void AddEmp(Employee* emp);
	void AddPatients(Patient* pat);
	void AddNurse();
	void AddDoctor();
	void AddDepartment();
	void PrintDepartmentDetails();
	void PrintDoctorsDetails();
	void PrintSalary();
	void AddPatient();
	void AddCoronaTestToPatientById();
	void Releasing();
	void PrintExcellenceWorker();
	void PrintNurseWithSmallestSalary();
	void printHospList();
	bool checkHospName(string H_N);
public:
	CovidCrisis();
	~CovidCrisis();
	void Menu();
};
#endif // !COVIDCRISIS
