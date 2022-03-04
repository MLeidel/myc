// strrstr.c
#include "../myc.h"

/***
* strrstr returns a pointer to the last occurrence
* of a substring in a string.
***/

int main () {

    char str[] = "abc xxxx ghi jkl xxx pqr";

    puts(str);

    // find last "xxx" in str
    printf("strrstr returned: [%s]\n", strrstr(str, "xxx"));

    // for index use lastindexof
    printf("lastindexof returned: [%d]\n", lastindexof(str, "xxx"));

    return 0;
}
