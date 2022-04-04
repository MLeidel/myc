// flines.c
#include <myc.h>


void flines(int count[2], char * fn) {
    char line[1000000]; // 1MB
    int maxline = 0;
    FILE * f = open_for_read(fn);
    while(1) {
        fgets(line, 1000000, f);
        count[0]++;
        if(feof(f)) break;
        if(strlen(line) > maxline) {
            maxline = strlen(line);
        }
    }
    count[1] = maxline;
    fclose(f);
}


void main (int argc, char *argv[]) {

    if (argc < 2) {
       printf("Missing filename\n");
       exit(1);
    }

    int c[2] = {0,0};

    flines(c, argv[1]);

    printf("lines: %d  longest line: %d\n", c[0], c[1]);
}
