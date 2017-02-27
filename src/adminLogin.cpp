#include "stdafx.h"

using namespace std;

bool adminLogin()
{
	cin.ignore();							//flushes the input stream so that getline starts fresh
	for (int i = 0; i < MAX_PASSWORD_ATTEMPT; i++)
	{
		cout << "Please enter the password, or empty line to go back: ";
		string password;
		getline(cin, password);

		//testing to see if the password matches

		if (password == "")		//if they want to go back to the main menu
		{
			return false;						//take them back
		}
		else if (password == DEFAULT_ADMIN_PASSWORD)	//if they got the password correct
		{
			return true;
		}
		else
		{
			cout << "Incorrect password." << endl;
		}
	}
	cout << "You have reached max retry count." << endl;
	return false;
}