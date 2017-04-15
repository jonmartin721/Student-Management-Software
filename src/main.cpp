#include "stdafx.h"
#include "main.h"

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
		cout << "4. View all User Records" << endl;
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
		case 4:
			return VIEW_ALL_USERS;
		case 0:
			return EXIT;
		default:
			cout << "Invalid choice." << endl;
		}
	}
}

//admin menu is kinda depricated right now, there won't be any need for a login in this sense after the initial login screen
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
			searchStudent();
			break;
		}
		case VIEW_ALL_RECORD:
		{
			populateStudents();
			break;
		}

		case VIEW_ALL_USERS:
		{
			cout << "THis is working";
			view_users();
			break;
		}

		case NEW_STUDENT:
		{
			newStudent();
			break;
		}
		case DELETE_STUDENT:
		{
			deleteStudent();
			break;
		}

		case MODIFY_STUDENT:
		{
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