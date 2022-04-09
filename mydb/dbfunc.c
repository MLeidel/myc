/*** compile with comps3 dbfunc
* dbfunc.c
* TESTING mydb.h
* uses guns.db
*
* TABLE "guns"
*   "Num"   INTEGER,
*   "Year"  INTEGER,
*   "Month" INTEGER,
*   "Date"  TEXT,
*   "Reason"    TEXT,
*   "Education" TEXT,
*   "Sex"   TEXT,
*   "Age"   INTEGER,
*   "Race"  TEXT,
*   "Hispanic"  INTEGER,
*   "Placeofincident"   TEXT,
*   "Policeinvolvement" INTEGER
****/
#include "mydb.h"

/*
user function to handle result set
note:    may need many different callback functions and/or
         use the qid parameter to direct action in one callback
*/
static int resultset(void *qid, int argc, char **argv, char **col) {
    int i;

    // (const char*)qid;  // can use for process control or heading

    // one row: process each column in order of sql statement
    for(i = 0; i<argc; i++) {
       printf("%s = %s\n", col[i], argv[i] ? argv[i] : "NULL");
    }
    return 0;
}


int main() {
    int rc = 0;

    mydb_open("guns.db");  // the database pointer is now 'db'

    //char * sql = "select distinct education from guns";

    rc = sqlite3_exec(db,
                          "select distinct education from guns",
                          resultset,
                          "ITEM>>>>", // or whatever
                          0);  // or &err_msg

    printf("rc from exec was [%d]\n\n", rc);  // 1==ERROR, 0==SUCCESS

    printf("total rows = %i\n\n", mydb_count("guns", ""));  // -1==FAIL

    rc = mydb_names("guns");  // -1==FAIL

    printf("number of columns = [%d]\n", rc);

    for (int x=0; x < rc; x++) {
        printf("%s\n", mydb_col[x]);
    }

    sqlite3_close(db);
    return 0;
}