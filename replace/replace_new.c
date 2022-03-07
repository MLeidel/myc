// replace.c
#include "../myc.h"


/*
    replace_new is an alternative to replace
    This creates a new string with the replacements
    at the exact new length.

    since the new string is created on the heap free
    is needed to reclaim its memory.
*/


int main () {

    char mystr[64] = "Hello XXX \"and\" XXX Mike";

    printf("original: %s\n\n", mystr);

    char * newstr = replace_new(mystr, "X", "YY", 0);
    puts(newstr);  // Hello YYYYYY "and" YYYYYY Mike

    char * nw2str = replace_new(newstr, "YYY", "ABCDEFGHIJKLMNOPQRST", 1);
    puts(nw2str);  // Hello ABCDEFGHIJKLMNOPQRSTYYY "and" YYYYYY Mike

    free(newstr);
    free(nw2str);

    return 0;
}
