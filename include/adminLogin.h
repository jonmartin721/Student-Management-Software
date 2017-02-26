#ifndef ADMINLOGIN
#define ADMINLOGIN
#pragma once


//this header file just prototypes the function, the function definition is in adminLogin.cpp

void adminmenu();
bool deleteStudent(const unsigned long studentID);
bool modifyStudent(const unsigned long studentID);
bool newStudent();
bool admin;
Student searchStudent(const unsigned long studentID);

#endif