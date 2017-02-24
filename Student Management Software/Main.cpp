/*CS 3420 Project

Shell portion.
Needed Functions (as headers)

- new student (Javier)
- modify student (Yuntian)
- delete student  (Nhu)
- search student (Jon)
- view all students (Ali)
- log in as admin (Ali)

*/

using namespace std;

//include common libraries
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//create a stream to the csv file for testing

ifstream database("testDatabase.csv");

//include our headers
#include "newStudent.h"
#include "modifyStudent.h"
#include "deleteStudent.h"
#include "searchStudent.h"
#include "viewStudents.h"
#include "adminLogin.h"

//no private members because this is just a shell, security is not important here
class Student {

public:

	//member variables

	string lastName, firstName, username;
	unsigned long studentID;
	vector <string> classes, classGrades;
	double GPA;

	//member functions (will be defined in headers but placed here)

	bool adminLogin();
	bool deleteStudent(const unsigned long studentID);
	bool modifyStudent(const unsigned long studentID);
	bool newStudent();
	Student searchStudent(const unsigned long studentID);
	vector<Student> viewStudents();

};

//program begin

int main()

{

	//i will add a menu here

	return 0;
}