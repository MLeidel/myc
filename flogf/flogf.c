// flogf.c
#include "../myc.h"

/* flogf(FILE, format, data ...)
   use for logging and/or debugging
    Allowd Format Codes:
    %f       float / double
    %d       integer decimal
    %s       string
    %l       long
    %$       double %.2f
    Works like fprintf() except for the nominal format codes
*/

void main (int argc, char *argv[]) {
    int x = 123;
    long y = 1231231234;
    double amount = 98765.345;

    flogf(stdout, "%s %d \n", "Value of x:", x);

    flogf(stdout, "long value:%l\n", y);  // %l is long for flogf

    flogf(stderr, "log: %s line: %d -- amount: %$\n", __FILE__, __LINE__, amount);

    flogf(stdout, "%s Begin App!\n", date("%F %r"));

    FILE * log_file = open_for_append("logfile.txt");
    flogf(log_file, "%s Begin App!\n", date("%F %r"));
    fclose(log_file);


     // same as:
    // fprintf(stdout, "%s %d \n", "Value of x:", x);
    // fprintf(stderr, "log: %s line: %d -- amount: %$\n", __FILE__, __LINE__, amount);
    // fprintf(stdout, "%s Begin App!\n", date("%F %r"));
    // FILE * log_file = open_for_append("logfile.txt");
    // fprintf(log_file, "%s Begin App!\n", date("%F %r"));
    // fclose(log_file);

 /////////// OUTPUT ////////////
// Value of x: 123
// long value:1231231234
// log: flogf.c line: 62 -- amount: 98765.35
// 2022-03-29 02:12:24 PM Begin App!
//
}
