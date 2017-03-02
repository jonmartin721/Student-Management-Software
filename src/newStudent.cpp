#include "stdafx.h"
#include <fstream>

using namespace std;

bool newStudent()
{
	int ID;
	char Grade1, Grade2, Grade3, Grade4;
	string User_name, First_name, Last_name,
		Semester, Class1, Class2, Class3, Class4;

	ofstream myfile;
	myfile.open("test.csv", ios::app);

	cout << "Enter the ID number for the student: ";
	cin >> ID;
	cout << "Enter the user name for the student: ";
	cin >> User_name;

	cout << "Student first name: ";
	cin >> First_name;
	cout << "Student last name: ";
	cin >> Last_name;
	cout << "Enter the semester: ";
	cin >> Semester;

	cout << "Enter the name of class 1: ";
	cin >> Class1;
	cout << "Name of class 2: ";
	cin >> Class2;
	cout << "Name of class 3: ";
	cin >> Class3;
	cout << "Name of class 4: ";
	cin >> Class4;

	cout << "Grade for class 1: ";
	cin >> Grade1;
	cout << "Grade for class 2: ";
	cin >> Grade2;
	cout << "Grade for class 3: ";
	cin >> Grade3;
	cout << "Grade for class 4: ";
	cin >> Grade4;

	myfile << "\n" << ID << "," << User_name << "," << First_name << ","
		<< Last_name << "," << Semester << "," << Class1 << ","

		<< Class2 << "," << Class3 << "," << Class4 << ","
		<< Grade1 << "," << Grade2 << "," << Grade3 << ","
		<< Grade4;

	myfile.close();


	return true;
}