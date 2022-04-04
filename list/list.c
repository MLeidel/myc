// list.c
#include "../myc.h"


/*  To make this more "list like" use an emun to have
    an alpha designation for each numeric list item
*/
enum sales {CEO,SN,MODEL,PRICE,LOCATION,S1,S2,S3};



/*
                      _
                     (_)
      _ __ ___   __ _ _ _ __
     | '_ ` _ \ / _` | | '_ \
     | | | | | | (_| | | | | |
     |_| |_| |_|\__,_|_|_| |_|

 */


void main() {
    /*  Test the list functions on quoted fields in a csv string -
        To create a list from a string we need to know "ahead of time"
        the number of items (or the highest number of possible items)
        and the longest item in the list to be created.
        We also need to know the delimiter. This example supplies
        these values with "#define ...".
    */
    #define DELIM ","
    #define COLS 8
    #define LEN 32
    char linein[] = "\"E. Musk, CEO, Founder\",10012,\"Tesla V8\", 89123.59, \"Cincinati, OH\",11,43, 50";

    double total = 0.0;

    printf("%s\n", linein);

    /***
    * list_def establishes a new struct variable
    * and allocates memory to the arrray of strings
    * using its args of number and length of items
    ***/

    list my_list = list_def(COLS, LEN);

    /***
    * list_split then supplies content to the array of strings
    * in the list struct by parsing out delimited fields.
    ***/

    list_split(my_list, linein, DELIM);

    list_display(my_list);  // list the list item values to console

    /***
    * After each call to list_split items from the list array
    * may be accessed with .item[n]
    * NOTE: S1..S3 are enum vars
    ***/

    setlocale(LC_NUMERIC, "");
    for(int x = S1; x <= S3; x++) {
        total = strtod(my_list.item[PRICE], NULL) * atoi(my_list.item[x]);
        printf("field %d amount: %'12.2f\n", x, total);
    }

    /***
    * list_del frees memory that was allocated
    * to hold the parsed fields. Call this when
    * your're finished using the struct variable (list)
    ***/

    list_del(my_list);
}
