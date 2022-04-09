#ifndef MYDB
#define MYDB
/***
* mydb.h
* Uses sqlite3
* loads pointers to sqlite3 and err_msg
* Note: the db sqlite pointer can be "reused"
*       but must first be closed with sqlite3_close(db).
* Note: myc.h is used
* compiling: gcc -o $1 $1.c -lsqlite3 -std=c99
***/
#include <sqlite3.h>
#include <myc.h>

sqlite3 *db;        // needed for sqlite
char *mydb_err_msg = 0;  // needed for callback function
int mydb_int = 0;
char mydb_col[256][80] = {"\0"};;  // columns/max col name length ==16K

static int mydbcallback(void *qid, int argc, char **argv, char **col) {
    // action based on qid
    int i;
    if (equals(qid, "count")) {
        mydb_int = atoi(argv[0]);
    } else {
    if (equals(qid, "names")) {
        for (i=0; i < argc; i++) {
            strcpy(mydb_col[i], col[i]);
        }
        mydb_int = argc;
    } else
        fprintf(stderr, "\n mydbcallback problems!\n");
    }
    return 0;
}


/***
 *                      ____
 *       ____ ___  ____/ / /_      ____  ____  ___  ____
 *      / __ `__ \/ __  / __ \    / __ \/ __ \/ _ \/ __ \
 *     / / / / / / /_/ / /_/ /   / /_/ / /_/ /  __/ / / /
 *    /_/ /_/ /_/\__,_/_.___/____\____/ .___/\___/_/ /_/
 *                         /_____/   /_/
 *
 * sqlite3_open does not check for presence of db file
 * mydb_open checks and aborts when not present
 * The database pointer is always "db"
 * To use another database first close the one that's open
 */

void mydb_open(char * dbname) {
    int status;
    if (!file_exists(dbname)) {
        fprintf(stderr, "\nmydb_open > %s does not exist!\nWill create it...\n", dbname);
    }
    status = sqlite3_open(dbname, &db);
    if(status != SQLITE_OK) {
        fprintf(stderr, "\nmydb_open > %s open failed\n", dbname);
        exit(EXIT_FAILURE);
    }
}



/***
 *                      ____                               __
 *       ____ ___  ____/ / /_      _________  __  ______  / /_
 *      / __ `__ \/ __  / __ \    / ___/ __ \/ / / / __ \/ __/
 *     / / / / / / /_/ / /_/ /   / /__/ /_/ / /_/ / / / / /_
 *    /_/ /_/ /_/\__,_/_.___/____\___/\____/\__,_/_/ /_/\__/
 *                         /_____/
 *
 * inputs: table name, sql where clause
 * returns: int or -1 on FAILURE
 */
int mydb_count(char * tablename, char * where) {
    char sql[127];

    sprintf(sql, "select count(*) from %s %s", tablename, where);
    int rc = sqlite3_exec(db,
                          sql,
                          mydbcallback,
                          "count", // qid or ""
                          0);  // or &mydb_err_msg
    if (rc != 0)
        return -1;
    else
        return mydb_int;
}



/***
 *                      ____
 *       ____ ___  ____/ / /_       ____  ____ _____ ___  ___  _____
 *      / __ `__ \/ __  / __ \     / __ \/ __ `/ __ `__ \/ _ \/ ___/
 *     / / / / / / /_/ / /_/ /    / / / / /_/ / / / / / /  __(__  )
 *    /_/ /_/ /_/\__,_/_.___/____/_/ /_/\__,_/_/ /_/ /_/\___/____/
 *                         /_____/
 *
 * input: table name
 * returns: int (number of columns) or -1 on FAILURE
 * **mydb_col array contains column names
 */
int mydb_names(char * tablename) {
    char sql[63];  // col names will be in **mydb_col

    sprintf(sql, "select * from %s limit 1", tablename);
    int rc = sqlite3_exec(db,
                          sql,
                          mydbcallback,
                          "names", // qid or ""
                          0);  // or &mydb_err_msg
    if (rc != 0)
        return -1;
    else
        return mydb_int;
}

#endif