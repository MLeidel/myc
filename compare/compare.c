// compare.c
#include "../myc.h"

/***
* string "compare" function
*
* compare(STRING1, IS, STRING2)
*                 ">"
*                 "<"
*                 ">="
*                 "<="
*                 "=="
*         returns true or false
***/

void main (int argc, char *argv[]) {

    if (argc < 4) {
       printf("Missing Arguments\nstring1, opString, string2\n");
       exit(EXIT_FAILURE);
    }

    printf("%s  %s  %s is %s\n",
            argv[1], argv[2], argv[3],
            compare(argv[1], argv[2], argv[3]) ? "true" : "false");

    if (compare(argv[1], argv[2], argv[3]))
        puts("used in an 'if' statement = TRUE");
    else
        puts("used in an 'if' statement = FALSE");

    if (compare("Dogs", ">=", "Cats"))
        puts("Dogs are >= Cats is TRUE");
}
