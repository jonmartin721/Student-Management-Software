#pragma once

#include "stdafx.h"

using namespace std;

//this is not like the other header files, this has the student class in it.
//This doesn't need be to changed unless there is a structural problem.

class Student {

public:

	//member variables

	string lastName, firstName, username, semesterEnrolled;
	unsigned long studentID;
	vector <string> classes, classGrades;
	float GPA;

	//default constructor

	Student();

};