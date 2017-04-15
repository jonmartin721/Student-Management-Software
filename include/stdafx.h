#pragma once

//include common libraries
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <conio.h>
#include "sqlite3.h"


//include our headers, one for each function
#include "newStudent.h"
#include "modifyStudent.h"
#include "deleteStudent.h"
#include "searchStudent.h"
#include "viewStudents.h"
#include "adminLogin.h"
#include "databaseManager.h"
#include "userClass.h"
#include "studentClass.h"

extern Database<Student> db;

typedef enum
{
	GUEST,
	USER,
	ADMIN,
}SIMS_USER_TOKEN, *LPSIMS_USER_TOKEN;

typedef enum
{
	EXIT,
	LOGIN,
	LOGOUT,
	SEARCH_STUDENT,
	VIEW_ALL_RECORD,
	VIEW_ALL_USERS,
	NEW_STUDENT,
	DELETE_STUDENT,
	MODIFY_STUDENT,
}SIMS_OPERATION, *LPSIMS_OPERATION;

#ifdef _DEBUG
#define DPRINT(s) std::cout << s << std::endl;
#else
#define DPRINT(s)
#endif

#define UNIMPLEMENTED DPRINT(__func__ << " is umimplemented.")
#define FIXME(s) DPRINT("FIXME: " << s)