#include "stdafx.h"

using namespace std;

bool modifyStudent()
{
	unsigned long StudentID;
	cout << "Please enter the Student ID you want to modify: ";
	cin >> StudentID;
	int Index = searchStudentByID(StudentID);
	Student Target = db.GetItems()[Index];

	int option = 0;
	cout << "1. Student ID" << endl;
	cout << "2. User Name" << endl;
	cout << "3. First Name" << endl;
	cout << "4. Last Name" << endl;
	cout << "5. Enrolled Semester" << endl;
	cout << "6. Classes" << endl;
	cout << "7. Class Grades" << endl;
	cout << "0. Exit" << endl;
	cout << "Please enter the field you want to modify: ";
	cin >> option;

	string NewValue;
	cout << "Please enter the new value: ";
	cin >> NewValue;

	switch (option)
	{
	case 1:
	{
		Target.SetStudentID(stol(NewValue));
		break;
	}
	case 2:
	{
		Target.SetUserName(NewValue);
		break;
	}
	case 3:
	{
		Target.SetFirstName(NewValue);
		break;
	}
	case 4:
	{
		Target.SetLastName(NewValue);
		break;
	}
	case 5:
	{
		Target.SetSemesterEnrolled(NewValue);
		break;
	}
	case 6:
	{
		Target.GetClasses().clear();
		while (NewValue != "")
		{
			Target.AddClass(NewValue);
			cout << "Please enter next value, or empty to quit: ";
			cin >> NewValue;
		}
		break;
	}
	case 7:
	{
		Target.GetClassGrades().clear();
		while (NewValue != "")
		{
			Target.AddClassGrade(NewValue);
			cout << "Please enter next value, or empty to quit: ";
			cin >> NewValue;
		}
		break;
	}
	case 0:
		return false;
	default:
	{
		cout << "Invalid field." << endl;
		return false;
	}
	}

	db.UpdateItem(Index, Target);

	return true;
}
