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

	Student();

};
#endif
