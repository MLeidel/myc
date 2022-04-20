// lofrof.c
#include "../myc.h"
#define MAX_L 1024


char buf[MAX_L];
char *line = "Lorem ipsum dolor sit amet, consectetur adipiscing elit";

void main () {

    // [Lorem ipsum dolor sit ]
    printf("[%s]\n", lof(buf, line, "amet, ", 0));

    // [consectetur adipiscing elit]
    printf("[%s]\n", rof(buf, line, "amet, ", 0));

}


