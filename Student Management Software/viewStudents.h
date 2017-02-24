#ifndef VIEWSTUDENTS_H
#define VIEWSTUDENTS_H
#pragma once

using namespace std;
#include <string>
#include <vector>
#include "studentclass.h"

//this header file will have the definition of a function to modify a student record

//instantiate a default Student (w/ default constructor)
Student basicStudent;
//instantiate a default vector to return student records
vector<Student> allStudents;


vector<Student> Student::viewStudents()
{

	allStudents.push_back(basicStudent);
	return allStudents;
}

#endif