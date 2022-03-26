// concat.c
#include "../myc.h"

char *conca(char *dest, int num, ...) {
    char *p = dest;
    va_list ap;

    va_start(ap, num);

    strcat(p, va_arg(ap, char*));  // first one

    for(int x=0; x < num-1; x++) {
        strcat(p, va_arg(ap, char*));
    }

    va_end(ap);
    return p;
}


int main (int argc, char *argv[]) {

    char s[10] = {'\0'};

    //strcpy(s, "Mrs. ");

    conca(s, 3, "Mary ", "Elizabeth ", "Smith");

    puts(s);

    return 0;
}
