#include "stdafx.h"

using namespace std;

//this header file will have the definition of a function to modify a student record

//instantiate a default Student (w/ default constructor)
Student default2;
//instantiate a vector to return student records
vector<Student> allStudents;

vector<Student> viewStudents()
{

	allStudents.push_back(default2);
	return allStudents;
}