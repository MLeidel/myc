/***
* field function
* consecutive space treated as one delimiter
***/
#include "../myc.h"

/*
   Return field number x using space(s) as field delimiter
*/

#define DELIM ' '
#define COLS 3
char rec[] = "Author: \"Edgar, Allan, Poe\"   American";
char data[100];

void main() {

   printf("\noriginal: %s\n", rec);

   for (int x=0; x < COLS; x++) {
      printf("field %d: [%s]\n", x, field(data, rec, DELIM, x, true));
   }

   printf("original: %s\n\n", rec);
}
