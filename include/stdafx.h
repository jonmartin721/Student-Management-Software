#pragma once

//include common libraries
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <conio.h>

//include the student class (is it's own header file)
#include "studentClass.h"

//include our headers, one for each function
#include "newStudent.h"
#include "modifyStudent.h"
#include "deleteStudent.h"
#include "searchStudent.h"
#include "viewStudents.h"
#include "adminLogin.h"
#include "populateStudents.h"


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