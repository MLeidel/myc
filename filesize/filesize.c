//filesize.c
#include <myc.h>

// long filesize(const char *filename) {
//     FILE *f;
//     if ((f = fopen(filename,"rb")) == NULL) {
//         ERRMSG(errno, false, "fopen: error on filesize function");
//         return -1;
//     }
//     fseek(f, 0, SEEK_END);
//     long fsize = ftell(f);
//     fclose(f);
//     return fsize;
// }


void main (int argc, char *argv[]) {

    long fs;
    fs = filesize("filesize");
    printf("%ld\n\n", fs);


    // example:
    cstr f = cstr_new(filesize("textfile.txt"), '\0');
    int r = readfile(f.str, "textfile.txt");
    puts(f.str);
    cstr_del(f);
}
