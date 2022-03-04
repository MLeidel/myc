// ERRMSG.c
#include "../myc.h"

// #define ERRMSG(a, b, c) (errmsg(a, b, c, __LINE__))

// /*
//     errmsg works with the ERRCHK macro
//     use ERRCHK with three arguments:
//     1> the return code to be checked
//     2> true or false to terminate the program
//     3> an additional error or debug message (string)
// */
// void errmsg(int rc, bool quit, char *msg, int line) {
//     fprintf(stderr,
//         "\n%s line: %d errno: %d %s\n%s\n",
//         __FILE__, line,
//         rc,
//         strerror(rc),
//         msg
//         );
//     if (quit) {  // print additional line and terminate program
//         fprintf(stderr, "Program Exited\n");
//         exit(EXIT_FAILURE);
//     }
// }


// EXAMPLE

void main (int argc, char *argv[]) {

    char fpath[MAX_L];

/*
    realpath returns NULL on failure
    It also sets errno on failure
*/

    if (realpath("../fiel", fpath) == NULL) {
        ERRMSG(errno, true, "realpath returned NULL");
    } else {
        puts(fpath);
    }
}

/* OUTPUT

ERRMSG near line: 40, errno: 2 No such file or directory
realpath returned NULL
Program Exited

*/