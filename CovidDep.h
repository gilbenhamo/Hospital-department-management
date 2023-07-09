#include "Doctor.h"
#include "Nurse.h"
#include "Patient.h"

#ifndef COVIDDEP
#define COVIDDEP

class CovidDep
{
	string hosp_name;
	Doctor** DocArr;
	int DocArrSize;
	Nurse** NurArr;
	int NurArrSize;
	Patient** PatArr;
	int PatArrSize;
public:
	CovidDep(string = "Unknown");
	CovidDep(const CovidDep&);
	~CovidDep();
	void AddDoc(Doctor* ND);
	void AddNurse(Nurse* NN);
	void AddPat(Patient* NP);
	void printDep();
	Doctor* GetDocPtr(int index);
	Nurse* GetNurPtr(int index);
	Patient* GetPatPtr(int index);
	int getDocSize() { return DocArrSize; }
	int getNurSize() { return NurArrSize; }
	int getPatSize() { return PatArrSize; }
	string getHospName() { return hosp_name; }
	void ReleaseById(string id);


	void setHospName(string H_N) { hosp_name = H_N; }
};
#endif // !COVIDDEP
