#include "CovidCrisis.h"
#define HOSP_SIZE 5

void CovidCrisis::printOptions()
{

		cout << "Menu: " << endl;
		cout << "1. ADD NURSE" << endl;
		cout << "2. ADD DOCTOR" << endl;
		cout << "3. ADD DEPARTMENT" << endl;
		cout << "4. PRINT DEPARTMENT DETAILS" << endl;
		cout << "5. PRINT DOCTORS DETAILS" << endl;
		cout << "6. PRINT SALARY BY ID" << endl;
		cout << "7. ADD PATIENT" << endl;
		cout << "8. ADD CORONA TEST TO PATIENT ID" << endl;
		cout << "9. RELEASING PATIENTS" << endl;
		cout << "10. PRINT EXCELLENCE WORKER" << endl;
		cout << "11. PRINT NURSE DETAILS WITH SMALLEST SALARY" << endl;
		cout << "12. EXIT" << endl;
}

bool CovidCrisis::searchID(string id)
{
	for (int i = 0; i < empSize; i++) //search in employee arr for the sent id
		if (id == employees[i]->getId())
			return true;
	return false;
}

void CovidCrisis::AddEmp(Employee * emp)
{
	empSize++;
	Employee** temp = employees;  //temporary arr to save the data
	employees = new Employee*[empSize];
	for (int i = 0; i < empSize; i++)   // copy the pointer
	{
		if (i == empSize - 1)  //add the new emp ptr to the end of the array
			employees[i] = emp;
		else
			employees[i] = temp[i];
	}
	delete[] temp; // delete the old arr;
}

void CovidCrisis::AddPatients(Patient * pat)
{
	patSize++;
	Patient** temp = patients;  //temporary arr to save the data
	patients = new Patient*[patSize];
	for (int i = 0; i < patSize; i++)   // copy the pointer
	{
		if (i == patSize - 1)  //add the new pat ptr to the end of the array
			patients[i] = pat;
		else
			patients[i] = temp[i];
	}
	delete[] temp; // delete the old arr;
}

void CovidCrisis::AddNurse()
{
	string h_n;
	bool idFlag = false, depflag = false; //flags to indacte if somthing happen
	bool inpflag = false;
	printHospList();
	cin.ignore();
	do // check for valid hosp name
	{
		if (inpflag)
				cout << "Try again!, choose only from the list!\n";
		cout << "Enter hospital: ";
		getline(cin, h_n);
		inpflag = true;
	} while (!(checkHospName(h_n)));
	Nurse* NewNurse = new Nurse(h_n);//create new nurse 
	NewNurse->setDep(h_n);
	cin >> *NewNurse;
	idFlag = searchID(NewNurse->getId());
	if (!idFlag)
	{
		for (int i = 0; i < depSize; i++)
		{
			if (departments[i]->getHospName() == NewNurse->getDep())
			{
				departments[i]->AddNurse(NewNurse); //if the id dont exsist add the nurse to the dep
				AddEmp(NewNurse);
				depflag = true;
			}
		}
		if (!depflag)
			cout << "The require hospital dont have corona department!\n";
	}
	else
	{
		cout << "This person ID is already exsist in the system!\n";
	}

}

void CovidCrisis::AddDoctor()
{
	string h_n;
	bool idFlag = false, depflag = false;
	bool inpflag = false;
	printHospList();
	cin.ignore();
	do //get the hospital name from the list only valid name
	{
		if (inpflag)
			cout << "Try again!, choose only from the list!\n";
		cout << "Enter hospital: ";
		getline(cin, h_n);
		inpflag = true;
	} while (!(checkHospName(h_n))); // check for validation
	Doctor* NewDoc = new Doctor;
	NewDoc->setDep(h_n);
	cin >> *NewDoc;
	idFlag = searchID(NewDoc->getId());
	if (!idFlag)
	{
		for (int i = 0; i < depSize; i++)
		{
			if (departments[i]->getHospName() == NewDoc->getDep())
			{
				departments[i]->AddDoc(NewDoc); //if the id dont exsist add the doctor to the deparment
				AddEmp(NewDoc);
				depflag = true;
			}
		}
		if (!depflag)
			cout << "The require hospital dont have corona department!\n";
	}
	else
	{
		cout << "This person ID is already exsist in the system!\n";
	}

}

void CovidCrisis::AddDepartment()
{
	string Hosp_N;
	bool HNflag = false;
	bool inpflag = false;
	printHospList();
	cin.ignore();
	do
	{
		if (inpflag)
			cout << "Try again!, choose only from the list!\n";
		cout << "Enter hospital: ";
		getline(cin, Hosp_N);
		inpflag = true;
	} while (!(checkHospName(Hosp_N)));
	for (int i = 0; i < depSize; i++) //check if this hospital already exsist
		if (Hosp_N == departments[i]->getHospName())
			HNflag = true;
	if (!HNflag)
	{
		cout << "Enter details of the new department:\n";
		//cin.ignore();
		CovidDep tempDep(Hosp_N);
		depSize++;
		CovidDep** temp = departments;  //temporary arr to save the data
		departments = new CovidDep*[depSize];
		for (int i = 0; i < depSize; i++)   // copy the pointer
		{
			if (i == depSize - 1)  //add the new department ptr to the end of the array
				departments[i] = new CovidDep(tempDep);
			else
				departments[i] = temp[i];
		}
		delete[] temp; // delete the old arr;

		//enter the employees to the employees array
		for (int i = 0; i < departments[depSize - 1]->getDocSize(); i++) //adding the new doctors // check doubles later
			AddEmp(departments[depSize - 1]->GetDocPtr(i)); 
		for (int i = 0; i < departments[depSize - 1]->getNurSize(); i++) //adding the new doctors // check doubles later
			AddEmp(departments[depSize - 1]->GetNurPtr(i));
	}
	else
	{
		cout << "Corona department already exsist in this hospital!\n";
	}

}

void CovidCrisis::PrintDepartmentDetails()
{
	string hosp_n;
	bool exflag = false, inpflag = false;;
	cout << "Choose hospital from the list to print the corona department\n ~{ Sheba, Wolfson, Rambam, Assaf Harofeh, Soroka }~\n";
	cin.ignore();
	do
	{
		if (inpflag) // print only after first try
			cout << "Try again!, choose only from the list!\n";
		cout << "Enter hospital: ";
		getline(cin, hosp_n);
		inpflag = true;
	} while (!(checkHospName(hosp_n)));//validate
	for (int i = 0; i < depSize; i++)
	{
		if (hosp_n == departments[i]->getHospName())
		{
			departments[i]->printDep();
			exflag = true;
		}
	}
	if (!exflag)
		cout << "The desire department dont exsist!\n";
}

void CovidCrisis::PrintDoctorsDetails()
{
	Doctor* temp;
	cout << "----All departments Doctors details----\n";
	for (int i = 0; i < empSize; i++)
	{
		temp = dynamic_cast<Doctor*>(employees[i]);//check if the emp is doc and print the doc
		if (temp)
		{
			temp->print();
			cout << endl;
		}

	}

}

void CovidCrisis::PrintSalary()
{
	string ID;
	bool exflag = false;
	cout << "\n----PRINT SALARY BY ID-----\nEnter id:";
	cin >> ID;
	for (int i = 0; i < empSize; i++) //search for the right id
	{
		if (ID == employees[i]->getId())
		{
			cout << "ID: " << ID << " Salary is: " << employees[i]->getSalary() << endl;
			exflag = true;
		}
	}
	if (!exflag)
		cout << "This id dont exsist in the system. Try again!\n";
}

void CovidCrisis::AddPatient()
{
	string h_n;
	bool idFlag = false, depflag = false;;
	bool inpflag = false;
	printHospList();
	cin.ignore();
	do //get the hospital name from the list only valid name
	{
		if (inpflag)
			cout << "Try again!, choose only from the list!\n";
		cout << "Enter hospital: ";
		getline(cin, h_n);
		inpflag = true;
	} while (!(checkHospName(h_n))); // check for validation
	Patient* NewPat = new Patient(h_n);
	NewPat->setDep(h_n);
	cin >> *NewPat;
	idFlag = searchID(NewPat->getId());
	if (!idFlag)
	{
		for (int i = 0; i < depSize; i++)
		{
			if (departments[i]->getHospName() == NewPat->getDep())
			{
				departments[i]->AddPat(NewPat);//if the id dont exsist add it to the dep
				AddPatients(NewPat); 
				depflag = true;
			}
		}
		if (!depflag)
			cout << "The require hospital dont have corona department!\n";
	}
	else
	{
		cout << "This person ID is already exsist in the system!\n";
	}

}

void CovidCrisis::AddCoronaTestToPatientById()
{
	string id;
	bool test = false, flag = false;
	cout << "~Add test to patient by ID~\n";
	cout << "Enter id: ";
	cin >> id;
	for (int i = 0; i < patSize; i++)
	{
		if (id == patients[i]->getId()) //if the person exsist add test to him
		{
			cout << "Enter 1 - Postive test OR 0 - for negative test\n";
			cin >> test;
			patients[i]->incTests(test);
			flag = true;
		}

	}
	if (!flag)
		cout << "This patient dont exsist in the system!\n";
}

void CovidCrisis::Releasing()
{
	string id, hosp;
	bool flag = false;
	for (int i = 0; i < patSize; i++) //search for who can be releasde
	{
		if (patients[i]->getNegative() >= 2)
		{
			flag = true;
			id = patients[i]->getId();
			hosp = patients[i]->getDep();
			patients[i] = 0; //target each patient that heald and put zero in the cell as indication
			for (int j = 0; j < depSize; j++)
			{
				if (departments[j]->getHospName() == hosp)
				{
					departments[j]->ReleaseById(id);
				}
			}
		}
	}
	if (flag) // at least one patient was recoverd
	{
		int index = 0;
		int count = 0;
		for (int i = 0; i < patSize; i++)
		{
			if (patients[i] == 0)
				count++;
		}
		patSize -= count; // minus all released patients
		Patient** temp = patients;  //temporary arr to save the data
		patients = new Patient*[patSize];
		for (int i = 0; i < (patSize + count); i++)   // copy the pointer
		{
			if (temp[i] != 0)
				patients[index++] = temp[i];
		}
		delete[] temp; // delete the old arr;
		cout << "All healed patients has been released from the hospital!\n";
	}
	else
		cout << "No patient meets the criterion, release no one!\n";
}

void CovidCrisis::PrintExcellenceWorker()
{
	bool flag = true;
	cout << "~List of Outstanding employees~\n\n";
	for (int i = 0; i < empSize; i++)
	{
		if (employees[i]->Outstanding())
		{
				employees[i]->print();
				cout << endl;
		}
	}
	if (!flag)
		cout << "There is none outstanding employees!\n";
}

void CovidCrisis::PrintNurseWithSmallestSalary()
{
	cout << "~ The nurse with the lowest salary ~\n\n";
	int min,index;
	bool flag = false;
	for (int i = 0; i < empSize; i++)
	{
		Nurse* temp = dynamic_cast<Nurse*>(employees[i]); //check if the emp is nurse
		if (temp)
		{
			if (!flag) //enter only in the first time the get the initial values
			{
				index = i;
				min = temp->getSalary();
				flag = true;
			}
			else
			{
				if (temp->getSalary() < min) //check if the values are lower than the save ones
				{
					min = temp->getSalary();
					index = i;
				}
			}
		}
	}
	employees[index]->print();
}

void CovidCrisis::printHospList()
{
	cout << "Please choose hospital from the list:\n{ Sheba, Wolfson, Rambam, Assaf Harofeh, Soroka }\n";
}

bool CovidCrisis::checkHospName(string H_N)
{
	string HospitalNames[] = { "Sheba", "Wolfson" , "Rambam", "Assaf Harofeh", "Soroka" };
	for (int i = 0; i < HOSP_SIZE; i++)
	{
		if (H_N == HospitalNames[i])
			return true;
	}
	return false;
}

CovidCrisis::CovidCrisis():depSize(1),patSize(0),empSize(3),patients(NULL)
{
	string h_n;
	cout <<"~Build first corona department~\n";
	bool inpflag = false;
	printHospList();
	do //get the hospital name from the list only valid name
	{
		if (inpflag)
			cout << "Try again!, choose only from the list!\n";
		cout << "Enter hospital: ";
		getline(cin, h_n);

		inpflag = true;
	} while (!(checkHospName(h_n))); // check for validation
	departments = new CovidDep*[1];
	departments[0] = new CovidDep(h_n);
	employees = new Employee*[3];
	employees[0] = departments[0]->GetDocPtr(0);
	employees[1] = departments[0]->GetNurPtr(0);
	employees[2] = departments[0]->GetNurPtr(1);
}

CovidCrisis::~CovidCrisis()
{
	for (int i = 0; i < depSize; i++)
		delete departments[i];
	delete[] departments;
	delete[] employees;
	delete[] patients;
}

void CovidCrisis::Menu()
{
		int option;
		bool run = true;
		while (run) {
			printOptions();
			cin >> option;
			switch (option) 
			{
			case 1:
				AddNurse();
				break;
			case 2:
				AddDoctor();
				break;
			case 3:
				AddDepartment();
				break;
			case 4:
				PrintDepartmentDetails();
				break;
			case 5:
				PrintDoctorsDetails();
				break;
			case 6:
				PrintSalary();
				break;
			case 7:
				AddPatient();
				break;
			case 8:
				AddCoronaTestToPatientById();
				break;
			case 9:
				Releasing();
				break;
			case 10:
				PrintExcellenceWorker();
				break;
			case 11:
				PrintNurseWithSmallestSalary();
				break;
			case 12:
				run = false;
				break;
			default:
				cout << "Invalid index, Try again!\n";
				break;
			}
		}

}
