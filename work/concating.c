// concating.c
#include "../myc.h"

void main () {

    char wrk[64];
    char *w1 = "one one one ";
    char *w2 = "two two two";

    int c = sprintf(wrk,"%s%s", w1, w2);
    printf("total characters: %d\n", c);
    puts(wrk);

    // vs ...

    puts(concat(wrk, 2, w1, w2));

}
