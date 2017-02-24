#ifndef ADMINLOGIN_H
#define ADMINLOGIN_H
#pragma once

//this is a test and now I'm adding more text

using namespace std;
#include <string>
#include <vector>
#include "studentclass.h"

//this header file will have the function to login as an admin

string passwordattempt;
string password = "testpassword";

bool Student::adminLogin()
{
	system("cls");
	cout << "Admin password: ";
	cin >> passwordattempt;

	if (passwordattempt == password)
	{
		return true;
	}
	else
		return false;
}

#endif