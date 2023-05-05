// cliptest.c
// #include <myc.h>
#include "../myc.h"

/*
int cbcopy(char *text)     // copy to clipboard
char *cbpaste(char *text)  // paste from clipboard
*/


void main (int argc, char *argv[]) {

    char txt[10240] = {'\0'};

    // if (argc < 2) {
    //    printf("Missing string to copy into clipboard\n");
    //    exit(1);
    // } else
    //     cbcopy(argv[1]);

    puts(cbpaste(txt));

}
