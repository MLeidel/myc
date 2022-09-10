// center.c
#include "../myc.h"


/* WARNING DANGEROUS: POSSIBLE OVERFLOW
    expanded string `space` must be accounted for
    allow enough characters in space
    HERE n is the length of the final string (space)
*/
// char * center(char *space, char *str, char *filler, int n) {
//     int sides = 0;
//     int size = 0;
//     int i = 0;

//     size = strlen(str);
//     sides = (n - size) / 2;

//     lpad(space, str, filler, sides);
//     rpad(space, space, filler, sides);

//     return space;
// }

void main (int argc, char *argv[]) {

    char buff[80] = {'\0'};  // to store results

    center(buff, "Hello World!", "^", 78);

    printf("%s\n", buff);
}

/*
output:
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^Hello World!^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
*/