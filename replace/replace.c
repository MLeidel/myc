// replace.c
#include "../myc.h"


void main () {

    char mystr[50] = "The long and winding road.";
    char newstr[50];

    printf("size of new buffer: %ld\n", sizeof(newstr));
    printf("size actual new buf: %d\n", replacesz(mystr, " ", ", ", 1));

    puts(replace(newstr, mystr, " ", ", ", 8, 1));
    // The long, and winding road.

    replace(newstr, newstr, "and ", "", 0, 0);
    puts(newstr);  // The long, winding road.
}
