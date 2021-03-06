#include "stdafx.h"

using namespace std;

int searchStudentByID(unsigned long ID)
{
	vector<Student> Students = db.GetItems();
	for (int i = 0; i < Students.size(); i++)
	{
		if (ID == Students[i].GetStudentID())
		{
			return i;
		}
	}

	return -1;
}

void searchStudent()
{
	int choice;
	vector<Student> Students = db.GetItems();
	//Outputs table Name
	cout << "Student Records Information System: Search Student Records" << endl;
	cout << endl;
	cout << "Types of Searches:" << endl;
	cout << "1. ID " << endl;
	cout << "2. Username " << endl;
	cout << "3. Name " << endl;
	cout << "0. Exit " << endl;
	cout << "What type of search are you looking for? ";
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		unsigned long id;
		cout << "Enter the ID you want to lookup: ";
		cin >> id;
		cout << endl;

		db.GetItems()[searchStudentByID(id)].Print();
		break;
	}
	case 2:
	{
		string username;
		cout << "Enter the Username you want to lookup: ";
		cin >> username;
		FIXME("Implement search based on username.");
		break;
	}
	case 3:
	{
		string name;
		cout << "Enter the Name you want to lookup: ";
		cin >> name;
		FIXME("Implement search based on name.");
		break;
	}
	case 0:
	{
		return;
	}
	default:
	{
		cout << "invalid option!" << endl;
		break;
	}
	}
}