#include "stdafx.h"

Users::Users()
{

	access_type = 1;
	username = "admin";
	password = "password";
}

//setters

void Users::setType (int)
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

int Users::getType()
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