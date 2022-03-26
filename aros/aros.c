/* aros.c
Demo/Test the aros functions
*/
#include "../myc.h"

/*
typedef struct aros {
    int nbr_rows;   // maximum records (columns, fields)
    int len_rows;  // maximum length allowed for each record (col|field|item)
    char ** item; // array of fields (array of strings)
} aros;
*/

enum sales {CEO,SN,MODEL,PRICE,LOCATION,S1,S2,S3};  // name for each field (optional)

int main(int argc, char const *argv[])
{
    /* Test the aros functions on quoted fields in a csv string
    */
    #define DELIM ","
    #define COLS 8
    #define LEN 32
    char linein[] = "\"E. Musk, CEO, Founder\",10012,\"Tesla V8\", 89123.59, \"Cincinati, OH\",11,43, 50";

    double total = 0.0;
    char *eptr;

    printf("%s\n", linein);

    /***
    * aros_new establishes a new struct variable
    * and allocates memory to the arrray of strings
    * using its args of number and length of items
    ***/

    aros list = aros_new(COLS, LEN);

    /***
    * aros_parse then supplies content to the array of strings
    * in the aros struct by parsing out delimited fields.
    ***/

    aros_parse(list, linein, DELIM);

    aros_display(list);  // list the list item values to console

    /***
    * After each call to aros_parse items from the aros array
    * may be accessed with .item[n]
    * NOTE: S1..S3 are enum vars
    ***/

    setlocale(LC_NUMERIC, "");
    for(int x = S1; x <= S3; x++) {
        total = strtod(list.item[PRICE], &eptr) * atoi(list.item[x]);
        printf("field %d amount: %'12.2f\n", x, total);
    }

    /***
    * aros_del frees memory that was allocated
    * to hold the parsed fields. Call this when
    * your're finished using the struct variable (list)
    ***/

    aros_del(list);

    return 0;
}
