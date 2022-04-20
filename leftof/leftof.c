// leftof.c (and rightof())
#include "../myc.h"
#define MAX_L 4096

/*
    As demonstrated below it is easy enough to use a simple
    combination of indexof() and substr() to obtain the same
    results. lof() and rof() now exist in myc.h and use this logic.
*/


char line[MAX_L];
char outline[MAX_L];
char *delim = ", ";
char *funcs[] = {"start=0 | delim=\", \"",
                 "start=30 | delim=\", \"",
                 "start=0 | delim=\", \"",
                 "start=30 | delim=\", \""};


void perform(int n) {
    strcpy(line, "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod");
    printf("\nline before -> [%s]\n", line);
    puts(funcs[n]);
    int inx = 0;

    switch (n) {
        case 0:
            inx = indexof(line, delim) + strlen(delim);
            printf("substr right of -> [%s]\n", substr(outline, line, inx, 0));
            break;
        case 1:
            inx = indexof(line+30, delim) + strlen(delim);
            printf("substr right of -> [%s]\n", substr(outline, line+30, inx, 0));
            break;
        case 2:
            inx = indexof(line, delim);
            printf("substr left of -> [%s]\n", substr(outline, line, 0, inx));
            break;
        case 3:
            inx = indexof(line+30, delim);
            printf("substr left of -> [%s]\n", substr(outline, line+30, 0, inx));
            break;
    }
    printf("line after  -> [%s]\n", line);
}


void main () {

    for(int x=0; x < 4; x++) {
        perform(x);
    }

}
