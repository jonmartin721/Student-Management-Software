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

Modify the .h file with the corresponding function assigned to you. Use the test.csv file to test your functions if you
have a function that would use a database. If you have a module that would need to modify the student class or this main.cpp file,
make a pull request so that we can make sure it will work.

Remember, we build this part first as if it is our actual program, then we
develop the real modules after.

*/

using namespace std;

//include common libraries
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//create a stream to the csv file for testing (this is the included resource file, test.csv)
ifstream database("test.csv");

//include our headers
#include "newStudent.h"
#include "modifyStudent.h"
#include "deleteStudent.h"
#include "searchStudent.h"
#include "viewStudents.h"
#include "adminLogin.h"

//include the student class (is it's own header file)
#include "studentclass.h"

int choice = 0;

int main()

{

	cout << "Student Records Management System (SRMS)" << endl;
	cout << "[READ ONLY] - LOGIN AS ADMIN TO MODIFY RECORDS" << endl;
	cout << "\nWelcome, please choose an option." << endl;
	cout << "1. Login as Admin" << endl;
	cout << "2. Search for Student" << endl;
	cout << "3. View all Student Records" << endl;
	cout << "4. Exit" << endl;
	cout << "\nChoice: ";
	cin >> choice;


	//other options will be created as part of the adminLogin part of this shell, they would only appear if the admin logged in

	
	//data validation with while loop

	while (choice < 1 || choice >4)
	{
		cout << "Student Records Management System (SRMS)" << endl;
		cout << "[READ ONLY] - LOGIN AS ADMIN TO MODIFY RECORDS" << endl;
		cout << "\nWelcome, please choose an option." << endl;
		cout << "1. Login as Admin" << endl;
		cout << "2. Search for Student" << endl;
		cout << "3. View all Student Records" << endl;
		cout << "4. Exit" << endl;
		cout << "\nChoice: ";
		cin >> choice;
	}

	if (choice == 4)
	{
		return 0;
	}

	return 0;
}