/* aros.c
*/
#include "../myc.h"

// typedef struct aros {
//     int nbr_rows;  // maximum records (columns, fields)
//     int len_rows; // maximum length of one record (col, field)
//     char ** item; // array of fields (array of strings)
// } aros;


enum sales {CEO,SN,MODEL,PRICE,LOCATION,S1,S2,S3};  // lends to readability

int main(int argc, char const *argv[])
{
    /* Test the aros functions on quoted fields in a csv string
    */
    #define DELIM ","
    #define COLS 8
    char linein[] = "\"E. Musk, CEO, Founder\",10012,\"Tesla V8\", 89123.59, \"Cincinati, OH\",11,43, 50";

    double total = 0.0;
    char *eptr;

    printf("%s\n", linein);

    /***
    * aros_new establishes a new struct variable
    * and allocates memory to the arrray of strings
    * using its args of number and length of items
    ***/
    aros list = aros_new(COLS, 64);

    /***
    * aros_parse then supplies content to the array of strings
    * in the aros struct by parsing out delimited fields.
    * aros_parse may be called as many times as needed.
    ***/
    aros_parse(list, linein, DELIM);

    aros_display(list);  // list the list item values to console

    /***
    * After each call to aros_parse items from the aros array
    * may be accessed with list.item[n] where "list" was the aros struct
    * and "n" is the index into each item.
    ***/
    for(int x = S1; x <= S3; x++) {
        total = strtod(list.item[PRICE], &eptr) * atoi(list.item[x]);
        printf("field %d amount: %.2f\n", x, total);
    }

    /***
    * aros_del frees memory that was allocated
    * to hold the parsed fields. Only call this after
    * your done parsing lines.
    ***/
    aros_del(list);

    return 0;
}
