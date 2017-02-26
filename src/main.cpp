/*CS 3420 Project

Testing commit on new PC.

Shell portion.
Needed Functions (as headers)

- new student (Javier)
- modify student (Yuntian)
- delete student  (Nhu)
- search student (Jon)
- view all students (Ali)
- log in as admin (Jon)

Modify the .cpp file with the corresponding function assigned to you. Use the test.csv file to test your functions if you
have a function that would use a database. If you have a module that would need to modify the student class or this main.cpp file,
make a pull request so that we can make sure it will work.

Remember, we build this part first as if it is our actual program, then we
develop the real modules after and incorporate them into this shell.

*/

//include common libraries
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//include our headers, one for each function
#include "newStudent.h"
#include "modifyStudent.h"
#include "deleteStudent.h"
#include "searchStudent.h"
#include "viewStudents.h"
#include "adminLogin.h"

//include the student class (is it's own header file)
#include "studentclass.h"

using namespace std;

//initialize some variables to help with the menu
int choice = 0;			//by default they choose 0
bool exitFlag = false;	//this is a flag that is triggered when the user wants to exit from the admin menu

int main()
{
	if (exitFlag == true) //if they wanted to exit from admin menu
	{
		return 0;
	}

	system("cls");
	choice = 0;
	cout << "Student Records Management System (SRMS)" << endl;
	cout << "[READ ONLY] - LOGIN AS ADMIN TO MODIFY RECORDS" << endl;
	cout << "\nWelcome User, please choose an option." << endl;
	cout << "1. Login as Admin" << endl;
	cout << "2. Search for Student" << endl;
	cout << "3. View all Student Records" << endl;
	cout << "4. Exit SRMS" << endl;
	cout << "\nChoice: ";
	cin >> choice;


	//data validation with while loop

	while (choice < 1 || choice > 4)
	{
		cout << "Student Records Management System (SRMS)" << endl;
		cout << "[READ ONLY] - LOGIN AS ADMIN TO MODIFY RECORDS" << endl;
		cout << "\nWelcome User, please choose an option." << endl;
		cout << "1. Login as Admin" << endl;
		cout << "2. Search for Student" << endl;
		cout << "3. View all Student Records" << endl;
		cout << "4. Exit SRMS" << endl;
		cout << "\nChoice: ";
		cin >> choice;
	}

	//start analyzing choices after validation passes

	if (choice == 1)		//if they choose to login as admin
	{
		admin = adminLogin();	//go to the adminLogin() function

		if (admin == true)		//if they got the password right
		{
			adminmenu();		//take them to the full menu
		}

		else					//if they did not the password right
		{
			main();				//take them back to read-only menu
		}

	}

	else if (choice == 2) //if they choose to search for a student
	{
		//Jon creates this function call and defines the function in searchStudent.h
	}

	else if (choice == 3) //if they choose to view all student records
	{
		//Ali creates this function call and defines the function in viewStudents.h
	}

	else if (choice == 4) //if they choose to Exit SRMS
	{
		return 0;				//Exit SRMS
	}

	main();
}

//admin version of the menu with extra options
void adminmenu()
{
	system("cls");

	choice = 0;
	cout << "Student Records Management System (SRMS)" << endl;
	cout << "[FULL ACCESS] - LOGGED IN AS ADMIN" << endl;
	cout << "\nWelcome Admin, please choose an option." << endl;
	cout << "1. Logout of Admin" << endl;
	cout << "2. Search for Student" << endl;
	cout << "3. View all Student Records" << endl;
	cout << "4. Exit SRMS" << endl;
	cout << "\nAdmin Only Functions:" << endl;
	cout << "5. Delete Student" << endl;
	cout << "6. Modify Student" << endl;
	cout << "7. New Student" << endl;
	cout << "\nChoice: ";
	cin >> choice;

	//data validation
	while (choice < 1 || choice > 7)
	{
		cout << "Student Records Management System (SRMS)" << endl;
		cout << "[FULL ACCESS] - LOGGED IN AS ADMIN" << endl;
		cout << "\nWelcome Admin, please choose an option." << endl;
		cout << "1. Logout of Admin" << endl;
		cout << "2. Search for Student" << endl;
		cout << "3. View all Student Records" << endl;
		cout << "4. Exit SRMS" << endl;
		cout << "\nAdmin Only Functions:" << endl;
		cout << "5. Delete Student" << endl;
		cout << "6. Modify Student" << endl;
		cout << "7. New Student" << endl;
		cout << "\nChoice: ";
		cin >> choice;
	}

	//start analyzing choices after validation check

	if (choice == 1)		//if they choose to logout from admin
	{
		admin = false;		//set them as a normal user
		main();				//go back to the main read-only menu

	}

	else if (choice == 2) //if they choose to search for a student
	{

	}

	else if (choice == 3) //if they choose to view all student records
	{

	}

	else if (choice == 4) //if they choose to Exit SRMS
	{
		exitFlag = true;
		main();			//Exit SRMS
	}

	else if (choice == 5) //if they choose to delete a student record
	{
		//Nhu creates this function call and defines the function in deleteStudent.h
	}

	else if (choice == 6) //if they choose to modify a student record
	{
		//Yuntian creates this function call and defines the function in modifyStudent.h
	}

	else if (choice == 7) //if they choose to create a new student record
	{
		//Javier creates this function call and defines the function in newStudent.h
	}

	return;

}