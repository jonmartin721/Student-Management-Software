#include "stdafx.h"

//this cpp file has the adminLogin function in it

string attemptedPassword;
string password = "testpassword";	//this is what the password is
int attemptedCount = 0;					//password attemptedCount

using namespace std;

bool adminLogin()
{
	system("cls");
	cout <<"Type 'Exit' to go back to read-only menu" << endl;
	cout << "attemptedCount left: " << 3 - attemptedCount << endl;
	cout << "\nAdmin password? ";
	cin.ignore();							//flushes the input stream so that getline starts fresh
	getline(cin, attemptedPassword);

											//testing to see if the password matches

	if (attemptedPassword == "Exit SRMS")		//if they want to go back to the main menu
	{
		return false;						//take them back
	}

	else if (attemptedPassword == password)	//if they got the password correct
	{
		cout << "\nPassword correct! Press enter to go to full menu.";
		cin.get();
		return true;
	}

	else
	{
		cout << "\nPassword incorrect! Press enter to try again.";
		attemptedCount++;
		cin.get();
		if (attemptedCount == 3)		//if they've tried unsuccessfully to enter the password 3 times
		{
			return false;		//return them to the main menu with read-only access
		}
		adminLogin();			//back to trying to enter password

	}
	return false;
}