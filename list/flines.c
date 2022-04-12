// flines.c
#include "../myc.h"


void main (int argc, char *argv[]) {

    if (argc < 2) {
       printf("Missing filename\n");
       exit(1);
    }

    int c[2] = {0,0};

    textlines(c, argv[1]);

    printf("lines: %d  longest line: %d\n", c[0], c[1]);
}
