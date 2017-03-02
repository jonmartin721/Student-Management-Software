#include "stdafx.h"

Student::Student()
{
	UNIMPLEMENTED;
	firstName = "Jacob";
	lastName = "Smith";
	userName = "smithj123";
	studentID = 900341854;
	classes.push_back("CS 3420");
	classGrades.push_back("B");
	semesterEnrolled = "Spring 2017";
	gpa = 3;
}

Student::Student(string CSVLine)
{
	istringstream Record(CSVLine);
	string Token;

	getline(Record, Token, ',');
	SetStudentID(stol(Token));

	getline(Record, Token, ',');
	SetUserName(Token);

	getline(Record, Token, ',');
	SetFirstName(Token);

	getline(Record, Token, ',');
	SetLastName(Token);

	getline(Record, Token, ',');
	SetSemesterEnrolled(Token);

	for (int i = 0; i < 4; i++)
	{
		getline(Record, Token, ',');
		AddClass(Token);
	}

	for (int i = 0; i < 4; i++)
	{
		getline(Record, Token, ',');
		AddClassGrade(Token);
	}

	getline(Record, Token, ',');
	SetGPA(stof(Token));
}

void Student::SetLastName(string LastName)
{
	lastName = LastName;
}

void Student::SetFirstName(string FirstName)
{
	firstName = FirstName;
}

void Student::SetUserName(string UserName)
{
	userName = UserName;
}

void Student::SetSemesterEnrolled(string SemesterEnrolled)
{
	semesterEnrolled = SemesterEnrolled;
}

void Student::SetStudentID(unsigned long StudentID)
{
	studentID = StudentID;
}

void Student::AddClass(string Class)
{
	classes.push_back(Class);
}

void Student::AddClassGrade(string ClassGrade)
{
	classGrades.push_back(ClassGrade);
}

void Student::SetGPA(float GPA)
{
	gpa = GPA;
}

string Student::GetLastName()
{
	return lastName;
}

string Student::GetFirstName()
{
	return firstName;
}

string Student::GetUserName()
{
	return userName;
}

string Student::GetSemesterEnrolled()
{
	return semesterEnrolled;
}

unsigned long Student::GetStudentID()
{
	return studentID;
}

vector<string> Student::GetClasses()
{
	return classes;
}

vector<string> Student::GetClassGrades()
{
	return classGrades;
}

float Student::GetGPA()
{
	return gpa;
}

void Student::Print()
{
	cout << this->studentID << " " << this->userName << " " << this->firstName << " " << this->lastName << " " << this->semesterEnrolled << " ";
	//Classes 1-4
	for (int j = 0; j < this->classes.size(); j++)
	{
		cout << this->classes[j] << " ";
	}
	//Class Grades 1-4
	for (int k = 0; k < this->classGrades.size(); k++)
	{
		cout << this->classGrades[k] << " ";
	}
	cout << this->gpa << endl;
}
