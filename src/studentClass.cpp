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
	size_t len = strlen(CSVLine.c_str()) + 1;
	char * Record = (char *) malloc(len);
	strcpy_s(Record, len, CSVLine.c_str());
	char * Token = NULL;
	char * NextToken = NULL;

	Token = strtok_s(Record, ",", &NextToken);
	SetStudentID(stol(Token));

	Token = strtok_s(NULL, ",", &NextToken);
	SetUserName(Token);

	Token = strtok_s(NULL, ",", &NextToken);
	SetFirstName(Token);

	Token = strtok_s(NULL, ",", &NextToken);
	SetLastName(Token);

	Token = strtok_s(NULL, ",", &NextToken);
	SetSemesterEnrolled(Token);

	for (int i = 0; i < 4; i++)
	{
		Token = strtok_s(NULL, ",", &NextToken);
		AddClass(Token);
	}

	for (int i = 0; i < 4; i++)
	{
		Token = strtok_s(NULL, ",", &NextToken);
		AddClassGrade(Token);
	}

	Token = strtok_s(NULL, ",", &NextToken);
	SetGPA(stof(Token));

	free(Record);
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
	return string();
}

string Student::GetUserName()
{
	return string();
}

string Student::GetSemesterEnrolled()
{
	return string();
}

unsigned long Student::GetStudentID()
{
	return 0;
}

vector<string> Student::GetClasses()
{
	return vector<string>();
}

vector<string> Student::GetClassGrades()
{
	return vector<string>();
}

float Student::GetGPA()
{
	return 0.0f;
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
