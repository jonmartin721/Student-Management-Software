#include "stdafx.h"

using namespace std;

Student searchStudent()
{
	system("cls");
	Student default;
	int choice;
	vector<Student> Students = db.GetItems();
	//Outputs table Name
	cout << "Student Records Information System: Search Student Records" << endl;
	cout << endl;
	cout << "Types of Searches:" << endl;
	cout << "1. ID " << endl;
	cout << "2. Username " << endl;
	cout << "3. Name " << endl;
	cout << "What type of search are you looking for? ";
	cin >> choice;
	if (choice == 1)
	{
		long int id;
		cout << "Enter the ID you want to lookup: ";
		cin >> id;
		cout << endl;
		for (auto i = Students.begin(); i != Students.end(); i++)
		{
			if (id == i->GetStudentID())
			{
				i->Print();
			}
		}

	}
	else if (choice == 2)
	{
		string username;
		cout << "Enter the Username you want to lookup: ";
		cin >> username;
		FIXME("Implement search based on username.");
	}
	else if (choice == 3)
	{
		string name;
		cout << "Enter the Name you want to lookup: ";
		cin >> name;
		FIXME("Implement search based on name.");
	}
	else
	{
		cout << "invalid option!" << endl;
	}
	return default;
}