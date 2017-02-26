#include "stdafx.h"

using namespace std;

//instantiate a default Student (w/ default constructor)
Student default;
//instantiate a vector to return student records
vector<Student> allStudents;

vector<Student> viewStudents()
{
	UNIMPLEMENTED;
	allStudents.push_back(default);
	return allStudents;
}