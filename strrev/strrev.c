// strrev.c
#include "../myc.h"

/***
* reverses the sequence of characters
* in a string
***/

int main () {

    char str[] = "He was a poor man on the streets";

    puts(str);

    // reverse str ...
    puts(strrev(str));

    return 0;
}
