/***
* Example.c
* Example.c
* Example.c
*
***/
#include "../myc.h"


char rec[] = "Author, \"Edgar, Allan, Poe\",   American";
char data[100];

void main() {

   for (int x=0; x < 3; x++) {
      printf("field %d: [%s]\n", x,
                        field(data, rec, ',', x, true));
   }
   /* output:
      field 0: [Author]
      field 1: ["Edgar, Allan, Poe"]
      field 2: [American]

   */

   for (int x=0; x < 3; x++) {
      printf("field %d: [%s]\n", x,
                        field(data, rec, ' ', x, true));
   }
   /* output:
      field 0: [Author,]
      field 1: ["Edgar, Allan, Poe",]
      field 2: [American]
   */
}
