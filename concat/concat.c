// concat.c
#include "../myc.h"

/*
    Note: s[64] (below) must be initialized for concat
    to function properly.
*/

int main (int argc, char *argv[]) {

    char s[64] = {'\0'};

    // strcpy(s, "Ms ");

    concat(s, "Mary ", "Elizabeth ", "Smith", END);

    puts(s);

    return 0;
}
