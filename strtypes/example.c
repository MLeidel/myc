// stypes.c
#include "../myc.h"


void main () {

    char string[] = "Amount: 123.21";

    printf("   ALPHA = %d\n", strtype(string, ALPHA));
    printf("   ALNUM = %d\n", strtype(string, ALNUM));
    printf("   DIGIT = %d\n", strtype(string, DIGIT));
    printf("   PUNCT = %d\n", strtype(string, PUNCT));
    printf("   PRINT = %d\n", strtype(string, PRINT));
    printf("   SPACE = %d\n", strtype(string, SPACE));
    printf("   UPPER = %d\n", strtype(string, UPPER));
    printf("   LOWER = %d\n", strtype(string, LOWER));

/* output:
   ALPHA = 6
   ALNUM = 11
   DIGIT = 5
   PUNCT = 2
   PRINT = -1
   SPACE = 1
   UPPER = 1
   LOWER = 5
*/

}
