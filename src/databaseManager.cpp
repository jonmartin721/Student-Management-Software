#include "stdafx.h"

using namespace std;


//const char *dbName = "Students.db";

//bool openDB()
//{
//	sqlite3 *db;
//	char *zErrMsg = 0;
//	int rc;
//	rc = sqlite3_open("Students.db", &db);
//
//	if (rc) {
//		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
//		return true;
//	}
//	else {
//		fprintf(stderr, "Opened database successfully\n");
//		return false;
//	}
//}


static int callback(void *data, int argc, char **argv, char **azColName) {
	int i;
	fprintf(stderr, "%s", (const char*)data);
	for (i = 0; i<argc; i++) {
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}

//int viewallstudents()
//{
//	sqlite3 *db;
//	char *zErrMsg = 0;
//	int rc;
//	char *sql;
//	const char* data = "";
//	const char* dbName = "Students.db";
//	/* Open database */
//	rc = sqlite3_open(dbName, &db);
//
//	/* Create SQL statement */
//	sql = " SELECT (a.First_Name || \" \" || a.Last_Name) AS 'Student Name',a.username, group_concat(ca.CRN) AS 'Class CRN', group_concat(c.Name) AS 'Class Name',group_concat(ca.Grade) AS 'Class Grade', group_concat(c.Instructor) AS Instructor FROM  Students AS a LEFT OUTER JOIN Records AS ca ON ca.username = a.username LEFT OUTER JOIN  Classes AS c ON ca.CRN = c.CRN GROUP  BY a.Last_Name, a.First_Name, a.username";
//	/* Execute SQL statement */
//	rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
//	if (rc != SQLITE_OK) {
//		fprintf(stderr, "SQL error: %s\n", zErrMsg);
//		sqlite3_free(zErrMsg);
//	}
//	
//	sqlite3_close(db);
//	return 0;
//}


//This function brings the student information together from multiple tables
bool populateStudents()
{
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	char *sql;
	const char* data = "";
	const char* dbName = "Students.db";
	vector<Student> Students;
	sqlite3_stmt *stmt;
	/* Open database */
	rc = sqlite3_open(dbName, &db);

	rc = sqlite3_prepare_v2(db,"SELECT a.First_Name , a.Last_Name,a.username, group_concat(c.Name || \" \" || c.CRN) AS 'Class Name',group_concat(ca.Grade) AS 'Class Grade', group_concat(c.Instructor) AS Instructor FROM  Students AS a LEFT OUTER JOIN Records AS ca ON ca.username = a.username LEFT OUTER JOIN  Classes AS c ON ca.CRN = c.CRN GROUP  BY a.Last_Name, a.First_Name, a.username"
	,
		-1, &stmt, NULL);
	if (rc != SQLITE_OK) {
		cerr << "SELECT failed: " << sqlite3_errmsg(db) << endl;
		return 0; // or throw
	}
	while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
		const char* firstName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
		const char* lastName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
		const char* username = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
		//const char* crn = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
		const char* classname = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
		const char* grade = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));
		const char* instructor = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5));
		// let's assume some fields can be NULL:
		Students.push_back(Student(firstName, lastName,username, classname ? classname : "-", grade ? grade : "-",instructor ? instructor : "-"));
		//Students.push_back(Student(firstName, lastName,username));
	}
	if (rc != SQLITE_DONE) {
		cerr << "SELECT failed: " << sqlite3_errmsg(db) << endl;
		// if you return/throw here, don't forget the finalize
	}
	sqlite3_finalize(stmt);

	//row counter
	int row = 1;
	//defines Student Class default
	Student default;
	//string manipulators for ouput 
	const char separator = ' ';
	const int nameWidth = 12;
	//Outputs table Name
	cout << "Student Records Information System: View All Students" << endl << endl;
	//outputs headers
	cout << setw(nameWidth) << setfill(separator) << "No." << " ";
	cout << setw(nameWidth) << setfill(separator) << "Username" << " ";
	cout << setw(nameWidth) << setfill(separator) << "First Name" << " ";
	cout << setw(nameWidth) << setfill(separator) << "Last Name" << " ";
	cout << setw(nameWidth) << setfill(separator) << "Classes" << " ";
	cout << setw(nameWidth) << setfill(separator) << "Grades" << " ";

	cout << endl;
	cout << "------------------------------------------------------------------------------------" << endl;
	//loops until the end of the file

	for (auto i = Students.begin(); i != Students.end(); i++) {
		// read a string until the next comma
		//row line
		cout << setw(nameWidth) << setfill(separator) << row << " ";
		//Username
		cout << setw(nameWidth) << setfill(separator) << i->GetUserName() << " ";
		//First Name
		cout << setw(nameWidth) << setfill(separator) << i->GetFirstName() << " ";
		//Last Name
		cout << setw(nameWidth) << setfill(separator) << i->GetLastName() << " ";
		
		for (int j = 0; j < i->GetClasses().size(); j++)
		{

			cout << setw(nameWidth) << setfill(separator) << i->GetClasses()[j] << " ";

		}
		//Class Grades 1-4
		for (int k = 0; k < i->GetClassGrades().size(); k++)
		{
			cout << setw(nameWidth) << setfill(separator) << i->GetClassGrades()[k] << " ";

		}
		cout << endl;

		row++;
	}


}

