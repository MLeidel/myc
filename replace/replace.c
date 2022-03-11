// replace.c
#include "../myc.h"


void main () {

    char mystr[64] = "The long and winding road.";
    char newstr[128];

    puts(replace(newstr, mystr, " ", ", ", 8, 1));
    // The long, and winding road.

    replace(newstr, newstr, "and ", "", 0, 0);
    puts(newstr);  // The long, winding road.
}
