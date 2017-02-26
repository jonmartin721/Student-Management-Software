#pragma once

#include "stdafx.h"

//this header file just prototypes the function, the function definition is in adminLogin.cpp

#define MAX_PASSWORD_ATTEMPT 3
#define DEFAULT_ADMIN_PASSWORD "password"

bool adminLogin();
