#pragma once

#include "stdafx.h"

using namespace std;

//this is not like the other header files, this has the student class in it.
//This doesn't need be to changed unless there is a structural problem.

class Student
{
private:
	//member variables
	string lastName, firstName, userName, semesterEnrolled;
	unsigned long studentID;
	vector <string> classes, classGrades;
	float gpa;
public:
	//default constructor
	Student();
	Student(string CSVLine);

	void SetLastName(string LastName);
	void SetFirstName(string FirstName);
	void SetUserName(string UserName);
	void SetSemesterEnrolled(string SemesterEnrolled);
	void SetStudentID(unsigned long StudentID);
	void AddClass(string Class);
	void AddClassGrade(string ClassGrade);
	void SetGPA(float GPA);

	string GetLastName();
	string GetFirstName();
	string GetUserName();
	string GetSemesterEnrolled();
	unsigned long GetStudentID();
	vector <string> GetClasses();
	vector <string> GetClassGrades();
	float GetGPA();

	void Print();

};