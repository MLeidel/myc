// strcon.c
// #include <myc.h>
#include "../myc.h"

/*  concatenate strings from an array of strings
    programmer is responsible for all bounds checking
    strcon(char*,   // return buffer
           char**,  // array of strings
           char*,   // delimiter
           int,     // rows in the array
           int);    // starting row number
*/


void main (int argc, char *argv[]) {

    char onestr[4096] = {'\0'}; // for the new SINGLE string

    char *people[] = {"Mike", "Mark", "Caren", "Coline", "Katy"};

    int sz = ARRSIZE(people);
    strcon(onestr, people, "^^", sz, 0);
    puts(onestr);


    if (argc > 1) {
        printf("argc = %d\n", argc);
        memset(onestr, '\0', 4096);
        int sz = argc;
        strcon(onestr, argv, " ", sz, 1);
        puts(onestr);
    }
}
