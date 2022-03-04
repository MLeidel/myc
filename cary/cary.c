/* cary.c
*/
#include "../myc.h"

/***
* Demo of cary
***/

enum sales {CEO,SN,MODEL,PRICE,LOCATION,S1,S2,S3};  // lends to readability

int main(int argc, char const *argv[])
{
    /* Test the cary functions on quoted fields in a csv string
    */
    #define DELIM ","
    #define COLS 8
    char linein[] = "\"E. Musk, CEO, Founder\",10012,\"Tesla V8\", 89123.59, \"Cincinati, OH\",11,43, 50";

    double total = 0.0;
    char *eptr;

    printf("%s\n", linein);

    /***
    * cary_new establishes a new struct variable
    * and allocates memory to the arrray of strings
    * using its args of number and length of items
    ***/
    cary list = cary_new(COLS, 64);

    /***
    * cary_parse then supplies content to the array of strings
    * in the cary struct by parsing out delimited fields.
    * cary_parse may be called as many times as needed.
    ***/
    cary_parse(list, linein, DELIM);

    cary_display(list);  // list the list item values to console

    /***
    * After each call to cary_parse items from the cary array
    * may be accessed with list.get[n] where "list" was the cary struct
    * and "n" is the index into each item.
    ***/
    for(int x = S1; x <= S3; x++) {
        total = strtod(list.get[PRICE], &eptr) * atoi(list.get[x]);
        printf("field %d amount: %.2f\n", x, total);
    }

    /***
    * cary_del frees memory that was allocated
    * to hold the parsed fields. Only call this after
    * your done parsing lines.
    ***/
    cary_del(list);

    return 0;
}
