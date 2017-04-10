#include "stdafx.h"

using namespace std;

Database<Student> db("test.csv");

SIMS_OPERATION displayGuestMenu()
{
	int option = 0;
	while (true)
	{
		cout << "Welcome User, please choose an option." << endl;
		cout << endl;
		cout << "1. Login as Admin" << endl;
		cout << "2. Search for Student" << endl;
		cout << "3. View all Student Records" << endl;
		cout << "0. Exit" << endl;
		cout << endl;
		cout << "Choice: ";
		cin >> option;

		switch (option)
		{
		case 1:
			return LOGIN;
		case 2:
			return SEARCH_STUDENT;
		case 3:
			return VIEW_ALL_RECORD;
		case 0:
			return EXIT;
		default:
			cout << "Invalid choice." << endl;
		}
	}
}

SIMS_OPERATION displayAdminMenu()
{
	int option = 0;
	while (true)
	{
		cout << "Welcome Admin, please choose an option." << endl;
		cout << endl;
		cout << "1. Logout of Admin" << endl;
		cout << "2. Search for Student" << endl;
		cout << "3. View all Student Records" << endl;
		cout << "4. Delete Student" << endl;
		cout << "5. Modify Student" << endl;
		cout << "6. New Student" << endl;
		cout << "0. Exit SIMS" << endl;
		cout << endl;
		cout << "Choice: ";
		cin >> option;

		switch (option)
		{
		case 1:
			return LOGOUT;
		case 2:
			return SEARCH_STUDENT;
		case 3:
			return VIEW_ALL_RECORD;
		case 4:
			return DELETE_STUDENT;
		case 5:
			return MODIFY_STUDENT;
		case 6:
			return NEW_STUDENT;
		case 0:
			return EXIT;
		default:
			cout << "Invalid choice." << endl;
		}
	}
}

SIMS_OPERATION displayMenu(LPSIMS_USER_TOKEN lpToken)
{
	cout << "Student Records Information System" << endl;
	switch (*lpToken)
	{
	case GUEST:
	case USER:
	{
		cout << "[READ ONLY] - LOGIN AS ADMIN TO MODIFY RECORDS" << endl;
		cout << endl;
		return displayGuestMenu();
	}
	case ADMIN:
	{
		cout << "[FULL ACCESS] - LOGGED IN AS ADMIN" << endl;
		cout << endl;
		return displayAdminMenu();
	}
	default:
	{
		cout << "Invalid user token." << endl;
		return EXIT;
	}
	}
}

int main()
{
	SIMS_USER_TOKEN Token = GUEST;

	while (true)
	{
		switch (displayMenu(&Token))
		{
		case LOGIN:
		{
			if (adminLogin()) Token = ADMIN;
			break;
		}
		case LOGOUT:
		{
			Token = GUEST;
			break;
		}
		case SEARCH_STUDENT:
		{
			//Jon creates this function call and defines the function in searchStudent.h
			searchStudent();
			break;
		}
		case VIEW_ALL_RECORD:
		{
			//Ali creates this function call and defines the function in viewStudents.h
			//viewStudents();
			populateStudents();
			break;
		}

		case NEW_STUDENT:
		{
			//Javier creates this function call and defines the function in newStudent.h
			newStudent();
			break;
		}
		case DELETE_STUDENT:
		{
			//Nhu creates this function call and defines the function in deleteStudent.h
			deleteStudent();
			break;
		}

		case MODIFY_STUDENT:
		{
			//Yuntian creates this function call and defines the function in modifyStudent.h
			modifyStudent();
			break;
		}
		case EXIT:
		{
			return 0;	//Exit SIMS
		}
		}

		cout << endl;
	}
}