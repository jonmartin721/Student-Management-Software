#pragma once

#include "stdafx.h"
using namespace std;

//this class is used solely for users logging in. no password security is present at this time
//functions defined in userclass.cpp
class Users
{
private:

	string access_type; 
	//3 = admin
	//2 = faculty
	//1 = student

	string username;
	//username

	string password;
	//password

public:

	Users();
	Users(const string & Username, const string & Password, const string & Access_Type);
	
	//setters

	void setType(string access_type);
	void setPassword(string password);
	void setUsername(string username);

	//getters

	string getType();
	string getUsername();
	string getPassword();

};