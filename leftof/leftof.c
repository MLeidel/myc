// leftof.c (and rightof())
#include "../myc.h"

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

    switch (n) {
        case 0:
            printf("rightof -> [%s]\n", rightof(outline, line, delim, 0));
            break;
        case 1:
            printf("rightof -> [%s]\n", rightof(outline, line, delim, 30));
            break;
        case 2:
            printf("leftof  -> [%s]\n", leftof(outline, line, delim, 0));
            break;
        case 3:
            printf("leftof  -> [%s]\n", leftof(outline, line, delim, 30));
            break;
    }
    printf("line after  -> [%s]\n", line);
}


void main () {

    for(int x=0; x < 4; x++) {
        perform(x);
    }

}
