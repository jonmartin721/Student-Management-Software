#ifndef STUDENTCLASS
#define STUDENTCLASS
#pragma once

using namespace std;

#include <string>
#include <vector>

//this is not like the other header files, this has the student class in it.
//This doesn't need be to changed unless there is a structural problem.

class Student {

public:

	//member variables

	string lastName, firstName, username;
	unsigned long studentID;
	vector <string> classes, classGrades;
	float GPA;

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
