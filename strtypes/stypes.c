// stypes.c
#include "../myc.h"

/***
* functions for string
* to compliment ctype.h
* functions for characters
* isalpha -> strtype(buf, ALPHA)
* isalnum -> strtype(buf, ALNUM)
* isdigit -> strtype(buf, DIGIT)
* isprint -> strtype(buf, PRINT)
* isspace -> strtype(buf, SPACE)
* isupper -> strtype(buf, UPPER)
* islower -> strtype(buf, LOWER)
* ispunct -> strtype(buf, PUNCT)
* Returns int:
*    0 = none found
*    N = number found
*   -1 = all found
***/


int main () {

    char line[10][20]={"abcdefg\0",
                       "A     G\0",
                       "a1b3c3d\0",
                       "-@#$%^&*\0",
                       "\t\n\0",
                       "501.99\0",
                       "\0",
                       " \0",
                       "123456\0",
                       " 12  \0"};


    for(int x=0; x < ARRSIZE(line); x++) {
        puts("vvvvvvvvvvvvvvvv");
        printf("[%s]\n", line[x]);
        printf("   ALPHA = %d\n", strtype(line[x], ALPHA));
        printf("   ALNUM = %d\n", strtype(line[x], ALNUM));
        printf("   DIGIT = %d\n", strtype(line[x], DIGIT));
        printf("   PUNCT = %d\n", strtype(line[x], PUNCT));
        printf("   PRINT = %d\n", strtype(line[x], PRINT));
        printf("   SPACE = %d\n", strtype(line[x], SPACE));
        printf("   UPPER = %d\n", strtype(line[x], UPPER));
        printf("   LOWER = %d\n", strtype(line[x], LOWER));
    }


    return 0;
}
