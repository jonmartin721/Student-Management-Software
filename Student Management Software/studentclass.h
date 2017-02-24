#ifndef STUDENTCLASS_H
#define STUDENTCLASS_H
#pragma once

using namespace std;

#include <string>
#include <vector>

class Student {

public:

	//member variables

	string lastName, firstName, username;
	unsigned long studentID;
	vector <string> classes, classGrades;
	float GPA;

	//member functions (will be defined in headers but placed here as a placeholder)

	bool adminLogin();
	bool deleteStudent(const unsigned long studentID);
	bool modifyStudent(const unsigned long studentID);
	bool newStudent();
	Student searchStudent(const unsigned long studentID);
	vector<Student> viewStudents();


	//default constructor

	Student()
	{
		firstName = "Jacob";
		lastName = "Smith";
		username = "smithj123";
		studentID = 900341854;
		classes.push_back("CS 3420");
		classGrades.push_back("B");
		GPA = 3;
	}

};
#endif
