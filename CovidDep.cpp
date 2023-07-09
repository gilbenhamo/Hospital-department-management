#include "CovidDep.h"

CovidDep::CovidDep(string HN):DocArrSize(1),NurArrSize(2),PatArrSize(0),hosp_name(HN)
{//build department with 1 doc and 2 nurses
	PatArr = NULL;
	DocArr = new Doctor*[1];
	DocArr[0] = new Doctor;
	cin >> *(DocArr[0]);
	DocArr[0]->setDep(HN);
	NurArr = new Nurse*[2];
	for (int i = 0; i < 2; i++)
	{
		cin.ignore();
		NurArr[i] = new Nurse;
		cin >> *(NurArr[i]);
		NurArr[i]->setDep(HN);
	}
}

CovidDep::CovidDep(const CovidDep& other):hosp_name(other.hosp_name), DocArrSize(other.DocArrSize), NurArrSize(other.NurArrSize), PatArrSize(other.PatArrSize)
{//coppy each array, check for NULL before
	if (DocArrSize <= 0)
	{
		DocArrSize = 0;
		DocArr = NULL;
	}
	else
	{
		DocArr = new Doctor*[DocArrSize];
		for (int i = 0; i < DocArrSize; i++)
		{
			DocArr[i] = new Doctor(*(other.DocArr[i]));
		}
	}
	if (NurArrSize <= 0)
	{
		NurArrSize = 0;
		NurArr = NULL;
	}
	else
	{
		NurArr = new Nurse*[NurArrSize];
		for (int i = 0; i < NurArrSize; i++)
		{
			NurArr[i] = new Nurse(*(other.NurArr[i]));
		}
	}
	if (PatArrSize <= 0)
	{
		PatArrSize = 0;
		PatArr = NULL;
	}
	else
	{
		PatArr = new Patient*[PatArrSize];
		for (int i = 0; i < PatArrSize; i++)
		{
			PatArr[i] = new Patient(*(other.PatArr[i]));
		}
	}
}

CovidDep::~CovidDep()
{//delete each arr**
	for (int i = 0; i < DocArrSize; i++)
		delete DocArr[i];
	delete[] DocArr;
	for (int i = 0; i < NurArrSize; i++)
		delete NurArr[i];
	delete[] NurArr;
	for (int i = 0; i < PatArrSize; i++)
		delete PatArr[i];
	delete[] PatArr;
}

void CovidDep::AddDoc(Doctor * ND)
{
	DocArrSize++;
	Doctor** temp = DocArr;  //temporary arr to save the data
	DocArr = new Doctor*[DocArrSize];
	for (int i = 0; i < DocArrSize; i++)   // copy the pointer
	{
		if (i == DocArrSize - 1)  //add the new doctor ptr to the end of the array
			DocArr[i] = ND;
		else
			DocArr[i] = temp[i];
	}
	delete[] temp; // delte the old arr;
}

void CovidDep::AddNurse(Nurse * NN)
{
	NurArrSize++;
	Nurse** temp = NurArr;  //temporary arr to save the data
	NurArr = new Nurse*[NurArrSize];
	for (int i = 0; i < NurArrSize; i++)   // copy the pointer
	{
		if (i == NurArrSize - 1)  //add the new nurse ptr to the end of the array
			NurArr[i] = NN;
		else
			NurArr[i] = temp[i];
	}
	delete[] temp; // delete the old arr;
}

void CovidDep::AddPat(Patient * NP)
{
	if (PatArrSize < 10)
	{
		if (DocArrSize >= 1 && NurArrSize >= 2)
		{
			PatArrSize++;
			Patient** temp = PatArr;  //temporary arr to save the data
			PatArr = new Patient*[PatArrSize];
			for (int i = 0; i < PatArrSize; i++)   // copy the pointer
			{
				if (i == PatArrSize - 1)  //add the new Patient ptr to the end of the array
					PatArr[i] = NP;
				else
					PatArr[i] = temp[i];
			}
			delete[] temp; // delete the old arr;
		}
		else
			cout << "You need at least 1 doctor and 2 nurses to add Patient to the department!\n";

	}
	else
		cout << "The department contains 10 patient already, you cant add anoter one";
}

void CovidDep::printDep()
{//print each arr in dep
	cout << "Hospital name: " << hosp_name << endl;
	cout << "--------Doctors list--------\n";
	if (DocArrSize == 0)
	{
		cout << "There is none doctors in the department!\n";
	}
	else
	{
		for (int i = 0; i < DocArrSize; i++)
			DocArr[i]->print();
		cout << endl;
	}
	cout << "--------Nurses list--------\n";
	if (NurArrSize == 0)
	{
		cout << "There is none Nurses in the department!\n";
	}
	else
	{
		for (int i = 0; i < NurArrSize; i++)
			NurArr[i]->print();
		cout << endl;
	}
	if (PatArrSize == 0)
	{
		cout << "There is none Patients in the department!\n";
	}
	else
	{

		cout <<"Number of Patients in the department: " <<PatArrSize << endl;
	}

}

Doctor* CovidDep::GetDocPtr(int index)
{
	return DocArr[index];
}

Nurse * CovidDep::GetNurPtr(int index)
{
	return NurArr[index];
}

Patient * CovidDep::GetPatPtr(int index)
{
	return PatArr[index];
}

void CovidDep::ReleaseById(string id)
{
	int index=0;
	PatArrSize--;
	Patient** temp = PatArr;  //temporary arr to save the data
	PatArr = new Patient*[PatArrSize];
	for (int i = 0; i < PatArrSize+1; i++)   // copy the pointer
	{
		if (temp[i]->getId() == id)  //loacted the patient by id
			delete temp[i]; // release the patient who recover from corona
		else
			PatArr[index++] = temp[i];
	}
	delete[] temp; // delete the old arr;
}
