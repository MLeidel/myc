//temp.c
#include <myc.h>


void main (int argc, char *argv[]) {

    char * str = "This is a temp string";
    char *p;

    if(strpbrk(str, "z")) {
        puts("found");
    }


}
