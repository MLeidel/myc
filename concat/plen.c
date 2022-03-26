//plen.c
#include <myc.h>

int getplen(char *b) {
    int c=0;
    while(*b != '\0') {
        c++;
        b++;
    }
    return c;
}


void main (int argc, char *argv[]) {

    char buf[10] = {'x'};



    printf("%d\n", getplen(buf));

}
