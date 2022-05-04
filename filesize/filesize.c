// filesize.c

#include "../myc.h"

void main (int argc, char *argv[]) {

    long fs;
    fs = filesize("textfile.txt");
    printf("%ld\n\n", fs);

}

