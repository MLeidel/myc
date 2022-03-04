// replace.c
#include "../myc.h"

int main () {

    char mystr[64] = "Hello XXX \"and\" XXX Mike";
    char newstr[128];

    printf("original: %s\n\n", mystr);

    puts(replace(newstr, mystr, "X", "YY", 0));  // Hello YYYYYY "and" YYYYYY Mike

    replace(newstr, newstr, "YYY", "ABCDEFGHIJKLMNOPQRST", 1);
                    // Hello ABCDEFGHIJKLMNOPQRSTYYY "and" YYYYYY Mike
    puts(newstr);

    return 0;
}
