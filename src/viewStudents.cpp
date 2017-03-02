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
	vector<Student> allStudents;
	//string to store read line from file
	string line;
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
		long int id = stol(line.c_str());
		cout << setw(nameWidth) << setfill(separator) << i->studentID << " ";
		//Username
		cout << setw(nameWidth) << setfill(separator) << default.username << " ";
		//First Name
		cout << setw(nameWidth) << setfill(separator) << default.firstName << " ";
		//Last Name
		cout << setw(nameWidth) << setfill(separator) << default.lastName << " ";
		//Semester Enrolled
		cout << setw(nameWidth) << setfill(separator) << default.semesterEnrolled << " ";
		//clears out previous student classes
		default.classes.clear();
		//Classes 1-4
		for (int i = 0; i < 4; i++)
		{

			if (line == "")
			{
				line = "-";
			}
			default.classes.push_back(line);
			cout << setw(nameWidth) << setfill(separator) << default.classes[i] << " ";
		
		}
		//clears out previours student grades
		default.classGrades.clear();
		//Class Grades 1-4
		for (int i = 0; i < 4; i++)
		{

			if (line == "")
			{
				line = "-";
			}
			default.classGrades.push_back(line);
			cout << setw(nameWidth) << setfill(separator) << default.classGrades[i] << " ";

		}

		//GPA
		float gpa = stof(line.c_str());
		default.GPA = gpa;
		cout << setw(nameWidth) << setfill(separator) << default.GPA << " ";
		cout << endl;

		allStudents.push_back(default);
		
		row++;
	}
	//press enter to go back to menu
	cout << endl;
	cout << "Press Enter to return to menu. " << endl;
	cin.get();
	system("cls");
}
