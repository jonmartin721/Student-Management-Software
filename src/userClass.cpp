#include "stdafx.h"

Users::Users()
{

	access_type = 1;
	username = "admin";
	password = "password";
}

Users::Users(const string & Username, const string & Password, const string & Access_Type)
{
	username = Username;
	password = Password;
	access_type = Access_Type;
}

//setters

void Users::setType (string)
{
	access_type = access_type;
}
void Users::setPassword(string)
{
	password = password;
}
void Users::setUsername(string)
{
	username = username;
}

//getters

string Users::getType()
{
	return access_type;
}

string Users::getUsername()
{
	return username;
}

string Users::getPassword()
{
	return password;
}