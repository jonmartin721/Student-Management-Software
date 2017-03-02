#include "stdafx.h"

using namespace std;

vector<Student> populateStudents()
{
	//defines Student Class default
	Student default;
	//Vector of class default
	vector<Student> allStudents;
	//Openes a filestream database with the test csv file
	ifstream database;
	database.open("test.csv");
	//string to store read line from file
	string line;
	//loops until the end of the file

	//while there is more data to read in the file
	while (!database.eof()) {
		// read a string until the next comma
		//ID
		getline(database, line, ',');
		long int id = stol(line.c_str());
		default.SetStudentID(id);
		//Username
		getline(database, line, ',');
		default.SetUserName(line);
		//First Name
		getline(database, line, ',');
		default.SetFirstName(line);
		//Last Name
		getline(database, line, ',');
		default.SetLastName(line);
		//Semester Enrolled
		getline(database, line, ',');
		default.SetSemesterEnrolled(line);
		//clears out previous student classes
		default.GetClasses().clear();
		//Classes 1-4
		for (int i = 0; i < 4; i++)
		{

			getline(database, line, ',');
			if (line == "")
			{
				line = "-";
			}
			default.AddClass(line);

		}
		//clears out previours student grades
		default.GetClassGrades().clear();
		//Class Grades 1-4
		for (int i = 0; i < 4; i++)
		{

			getline(database, line, ',');
			if (line == "")
			{
				line = "-";
			}
			default.AddClassGrade(line);

		}

		//GPA
		getline(database, line);
		float gpa = stof(line.c_str());
		default.SetGPA(gpa);

		allStudents.push_back(default);
	}
	database.close();
	return allStudents;
}