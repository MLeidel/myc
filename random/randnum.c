#include <stdio.h>
#include <stdlib.h>
#include "../myc.h"

/*
   seed the random number generator
   only do once

void randini() {
   srand(time(0));
}

*/
/*
   Returns a random number falling between
   MIN and MAX values

long randnum(long min, long max) {
   if(min>max)
   {
      printf("Min value is greater than max value\n");
      return 0;
   } else {
      return rand() % (max - min +1) + min;
   }
}
*/


int main () {
   int i;

   randini();

   for(i=0;i<50;i++) {
      printf("%d\n", randnum(100000000, 100999999));
   }

   printf("\n");
   return 0;
 }
