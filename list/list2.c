/* list2.c
*/
#include "../myc.h"

/***
*
* "list" also handles spaces as delimiter
* Consecutive ' ' treated as single delimiter
*
***/

void main() {
    #define DELIM " "

    #define COLS 3
    char linein[] = "Author: \"Edgar, Allan, Poe\"   American";
    char out[32];

    printf("%s\n\n", linein);

    list list = list_def(COLS, 32);

    list_split(list, linein, DELIM);

    list_display(list);  // list the list item values to console

    /*  list does not automatically remove quotes
        use 'deletechar' function to remove them
    */
    printf("field 1 with no quotes: [%s]\n",
           deletechar(out, list.item[1], "\"", 0, 0));

    list_del(list);

    puts("");
}
