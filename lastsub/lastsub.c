// lastsub.c
#include "../myc.h"

/***
* lastsub returns a pointer to the last occurrence
* of a substring in a string.
***/

int main () {

    char str[] = "abc xxxx ghi jkl xxx pqr";

    puts(str);

    // find last "xxx" in str
    printf("lastsub returned: [%s]\n", lastsub(str, "xxx"));

    // for index use lastindexof
    printf("lastindexof returned: [%d]\n", lastindexof(str, "xxx"));

    return 0;
}
