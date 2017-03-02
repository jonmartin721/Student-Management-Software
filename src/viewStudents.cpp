#include "stdafx.h"

using namespace std;

void viewStudents()
{

	system("cls");
	cin.ignore();
	//row counter
	int row = 1;
	//defines Student Class default
	Student default;
	//Vector of class default
	vector<Student> allStudents = populateStudents();
	//string manipulators for ouput 
	const char separator = ' ';
	const int nameWidth = 12;
	//Outputs table Name
	cout << "Student Records Information System: View All Students" << endl << endl;
	//outputs headers
	cout << setw(nameWidth) << setfill(separator) << "No." << " ";
	cout << setw(nameWidth) << setfill(separator) << "ID" << " ";
	cout << setw(nameWidth) << setfill(separator) << "Username" << " ";
	cout << setw(nameWidth) << setfill(separator) << "First Name"<< " ";
	cout << setw(nameWidth) << setfill(separator) <<"Last Name" << " ";
	cout << setw(nameWidth) << setfill(separator) << "Semester" << " ";
	cout << setw(nameWidth) << setfill(separator) << "Class 1" << " ";
	cout << setw(nameWidth) << setfill(separator) << "Class 2" << " ";
	cout << setw(nameWidth) << setfill(separator) << "Class 3" << " ";
	cout << setw(nameWidth) << setfill(separator) << "Class 4" << " ";
	cout << setw(nameWidth) << setfill(separator) << "Grade 1" << " ";
	cout << setw(nameWidth) << setfill(separator) << "Grade 2" << " ";
	cout << setw(nameWidth) << setfill(separator) << "Grade 3" << " ";
	cout << setw(nameWidth) << setfill(separator) << "Grade 4" << " ";
	cout << setw(nameWidth) << setfill(separator) << "GPA" << " ";
	cout << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	//loops until the end of the file
	
	//while there is more data to read in the file
	for (auto i = allStudents.begin(); i != allStudents.end(); i++) {
		// read a string until the next comma
		//row line
		cout << setw(nameWidth) << setfill(separator) << row << " ";
		//ID
		cout << setw(nameWidth) << setfill(separator) << i->studentID << " ";
		//Username
		cout << setw(nameWidth) << setfill(separator) << i->username << " ";
		//First Name
		cout << setw(nameWidth) << setfill(separator) << i->firstName << " ";
		//Last Name
		cout << setw(nameWidth) << setfill(separator) << i->lastName << " ";
		//Semester Enrolled
		cout << setw(nameWidth) << setfill(separator) << i->semesterEnrolled << " ";
		//Classes 1-4
		for (int j = 0; j <  i->classes.size(); j++)
		{

			cout << setw(nameWidth) << setfill(separator) << i->classes[j] << " ";
		
		}
		//Class Grades 1-4
		for (int k = 0; k < i->classGrades.size(); k++)
		{
			cout << setw(nameWidth) << setfill(separator) << i->classGrades[k] << " ";

		}

		//GPA
		cout << setw(nameWidth) << setfill(separator) << i->gpa << " ";
		cout << endl;
		
		row++;
	}
	//press enter to go back to menu
	cout << endl;
	cout << "Press Enter to return to menu. " << endl;
	cin.get();
	system("cls");
}
