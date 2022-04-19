//filesize.c
#include "../myc.h"


void main (int argc, char *argv[]) {

    long fs;
    fs = filesize("textfile.txt");
    printf("%ld\n\n", fs);


    // example:
    cstr f = cstr_def(filesize("textfile.txt"), '\0');
    int r = readfile(f.str, "textfile.txt");
    puts(f.str);
    cstr_del(f);
}
