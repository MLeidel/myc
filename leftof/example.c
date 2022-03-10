// example.c
#include "../myc.h"



char buf[MAX_L];
char *line = "Lorem ipsum dolor sit amet, consectetur adipiscing elit";

void main () {

    leftof(buf, line, "amet, ", 0);  // [Lorem ipsum dolor sit ]
    printf("[%s]\n", buf);

    printf("[%s]\n", rightof(buf, line, "amet, ", 0));
                                // [consectetur adipiscing elit]
}


