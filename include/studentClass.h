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
	Student(const string& FirstName,const string& LastName, string username, string className,string grade,string instructor);
	Student(const string& FirstName, const string& LastName, string username);

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

	string toString();
	void Print();
};

template <class T>
class Database
{
private:
	vector<T> Items;
	string CSV;
public:
	vector<T> GetItems()
	{
		return Items;
	}

	bool AddItem(const T NewItem)
	{
		Items.push_back(NewItem);
		return SaveCSV();
	}

	bool UpdateItem(int Index, const T NewItem)
	{
		Items[Index] = NewItem;
		return SaveCSV();
	}

	bool ImportCSV(const char * FileName)
	{
		CSV = FileName;
		ifstream File(CSV);

		while (!File.eof())
		{
			string Record;
			getline(File, Record);
			if (Record == "")
			{
				break;
			}
			T NewItem(Record);
			Items.push_back(Record);
		}

		return true;
	}

	bool SaveCSV()
	{
		ofstream File(CSV);
		for (auto i = Items.begin(); i < Items.end(); i++)
		{
			File << i->toString() << endl;
		}
		return true;
	}

	Database(const char * FileName)
	{
		ImportCSV(FileName);
	}

	~Database()
	{
		SaveCSV();
	}
};