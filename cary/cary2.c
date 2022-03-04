/* cary.c
*/
#include "../myc.h"

/***
*
* cary also handles spaces as delimiter
* Consecutive ' ' treated as single dilimiter
*
***/

int main()
{
    #define DELIM " "

    #define COLS 3
    char linein[] = "Author: \"Edgar, Allan, Poe\"   American";
    char noquo[64];
    char out[256];

    // #define COLS 6
    // char linein[] = "Author: Edgar , Allan,  Poe    American";

    printf("%s\n", linein);

    cary list = cary_new(COLS, 64);

    cary_parse(list, linein, DELIM);

    cary_display(list);  // list the list item values to console

    printf("field 1 with no quotes: [%s]\n", deletechar(out, list.get[1], '\"', 0));

    cary_del(list);

    return 0;
}
