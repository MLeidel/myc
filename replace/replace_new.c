// replace_new.c
#include "../myc.h"


/*
    replace_new is an alternative to replace
    This creates a new string with the replacements
    at the exact new length.

    since the new string is created on the heap free
    is needed to reclaim its memory.
*/


int main () {

    char mystr[64] = "Hello XXX \"and\" XXX Joe";

    printf("original: %s\n\n", mystr);

    char * newstr = replace_new(mystr, "X", "YY", 0, 0);
    puts(newstr);  // Hello YYYYYY "and" YYYYYY Joe

    char * nw2str = replace_new(newstr, "YYY", "ABCDEFGHIJ ", 12, 1);
    puts(nw2str);  // Hello YYYYYY "and" ABCDEFGHIJ YYY Joe

    free(newstr);
    free(nw2str);

    return 0;
}
