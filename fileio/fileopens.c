// fileopens.c
#include "../myc.h"
#define MAX_L 4096

/***
open_for_write
open_for_append
open_for_read
readfile
writefile
***/


int main (int argc, char *argv[]) {

    unlink("testfile.txt");  // delete the file if it exists.
    unlink("testfile.out");  // delete the file if it exists.


    FILE *fh = open_for_write("testfile.txt");

    fprintf(fh, "Here is line 1\n");

    fclose(fh);


    fh = open_for_append("testfile.txt");

    fprintf(fh, "Here is line 2 which was appended.\n");

    fclose(fh);

    char buf[MAX_L];

    fh = open_for_read("testfile.txt");
    puts("via open_for_read ...");
    do {
        fgets(buf, MAX_L, fh);
        if (feof(fh)) break;
        printf("%s", buf);
    } while(true);
    fclose(fh);

    memset(buf, '\0', MAX_L * sizeof(char));  // clear buf

    readfile(buf, "testfile.txt");

    puts("now via 'readfile' function ...");
    puts(buf);

    writefile(buf, "testfile.out", false);  // write
    writefile(buf, "testfile.out", true);  // append
    puts("created testfile.out and appended to it");

    return 0;
}
