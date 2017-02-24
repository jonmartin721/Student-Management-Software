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
string password = "testpassword";	//this is what the password is
bool admin = false;					//by default they are not an admin
int attempts = 0;					//password attempts

bool adminLogin()
{
	system("cls");
	cout << "Type 'Exit SRMS' to go back to read-only menu" << endl;
	cout << "Attempts left: " << 3 - attempts << endl;
	cout << "\nAdmin password? ";
	cin.ignore();
	getline(cin, passwordattempt);

	//testing to see if the password matches

	if (passwordattempt == "Exit SRMS")		//if they want to go back to the main menu
	{
		return false;							//take them back
	}

	else if (passwordattempt == password)	//if they got the password correct
	{
		cout << "\nPassword correct! Press enter to go to full menu.";
		cin.get();
		return true;
	}

	else
	{
		cout << "\nPassword incorrect! Press enter to try again.";
		attempts++;
		cin.get();
		if (attempts == 3) //if they've tried unsuccessfully to enter the password 3 times
		{
			return false; //return them to the main menu with read-only access
		}
		adminLogin(); //back to trying to enter password
	
	}
	return false;
}
#endif