#include "stdafx.h"

using namespace std;


//const char *dbName = "Students.db";

bool openDB()
{
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	rc = sqlite3_open("Students.db", &db);

	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		return true;
	}
	else {
		fprintf(stderr, "Opened database successfully\n");
		return false;
	}
}


static int callback(void *data, int argc, char **argv, char **azColName) {
	int i;
	fprintf(stderr, "%s", (const char*)data);
	for (i = 0; i<argc; i++) {
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}

int viewallstudents()
{
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	char *sql;
	const char* data = "";
	const char* dbName = "Students.db";
	/* Open database */
	rc = sqlite3_open(dbName, &db);

	/* Create SQL statement */
	sql = " SELECT (a.First_Name || \" \" || a.Last_Name) AS 'Student Name',a.username, group_concat(ca.CRN) AS 'Class CRN', group_concat(c.Name) AS 'Class Name', group_concat(c.Instructor) AS Instructor FROM  Students AS a LEFT OUTER JOIN Records AS ca ON ca.username = a.username LEFT OUTER JOIN  Classes AS c ON ca.CRN = c.CRN GROUP  BY a.Last_Name, a.First_Name, a.username";
	/* Execute SQL statement */
	rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	
	sqlite3_close(db);
	return 0;
}