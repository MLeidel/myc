/***
* getfield function parsing for SPACE delimeter ' '
* vs parsing for non-space character (like ',')
* Consecutive ' ' characters treated as ONE delimiter
*
***/
#include "../myc.h"

 ///////////////////////////////////////////////////////////////////
/* TEST CASES */

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
