// compare.c
#include "../myc.h"

/***
* string "compare" function
*
* compare(STRING1, IS, STRING2)
*
* Where "IS" may be any of the following:
*
*         ">"   |  GT  |  GreaterThan
*         "<"   |  LT  |  LessThan
*         ">="  |  GTE |  GreaterThanOrEqual
*         "<="  |  LTE |  LessThanOrEqual
*         "=="  |  EQ  |  Equal
*         "!="  |  NEQ |  NotEqual
*   returns true or false
***/

void main (int argc, char *argv[]) {

    if (argc < 4) {
       printf("Missing Arguments\nstring1, opString, string2\n");
       exit(EXIT_FAILURE);
    }

    // here must use "==,>,<,>=,..." symbols only !
    // because "argv" will not be expanded from macros
    if (compare(argv[1], argv[2], argv[3]))
        puts("used in an 'if' statement = TRUE");
    else
        puts("used in an 'if' statement = FALSE");

    // here the macro expands into ">="
    if (compare("Dogs", GreaterThanOrEqual, "Cats"))
        puts("\nDogs are >= Cats is TRUE");
}
