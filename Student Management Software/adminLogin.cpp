#include "adminLogin.h"
#include "studentclass.h"
#include <string>
#include <vector>
#include <iostream>

//this cpp file has the adminLogin function in it

string passwordattempt;
string password = "testpassword";	//this is what the password is
int attempts = 0;					//password attempts

using namespace std;

bool adminLogin()
{
	system("cls");
	cout <<"Type 'Exit' to go back to read-only menu" << endl;
	cout << "Attempts left: " << 3 - attempts << endl;
	cout << "\nAdmin password? ";
	cin.ignore();							//flushes the input stream so that getline starts fresh
	getline(cin, passwordattempt);

											//testing to see if the password matches

	if (passwordattempt == "Exit SRMS")		//if they want to go back to the main menu
	{
		return false;						//take them back
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
		if (attempts == 3)		//if they've tried unsuccessfully to enter the password 3 times
		{
			return false;		//return them to the main menu with read-only access
		}
		adminLogin();			//back to trying to enter password

	}
	return false;
}