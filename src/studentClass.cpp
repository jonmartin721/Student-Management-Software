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

Student::Student(const string & FirstName, const string& LastName, string username, string className, string grade, string instructor)
{
	lastName = LastName;
	firstName = FirstName;
	userName = username;
	classes.push_back(className);
	classGrades.push_back(grade);


}

Student::Student(const string & FirstName, const string & LastName, string username)
{
	lastName = LastName;
	firstName = FirstName;
	userName = username;
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

string Student::toString()
{
	return to_string(studentID) + "," + userName + "," + firstName + "," + lastName + "," + semesterEnrolled + "," +
		classes[0] + "," + classes[1] + "," + classes[2] + "," + classes[3] + "," +
		classGrades[0] + "," + classGrades[1] + "," + classGrades[2] + "," + classGrades[3] + "," +
		to_string(gpa);
}

void Student::Print()
{
	cout << studentID << " " << userName << " " << firstName << " " << lastName << " " << semesterEnrolled << " ";
	//Classes 1-4
	for (int j = 0; j < classes.size(); j++)
	{
		cout << classes[j] << " ";
	}
	//Class Grades 1-4
	for (int k = 0; k < classGrades.size(); k++)
	{
		cout << classGrades[k] << " ";
	}
	cout << gpa << endl;
}
