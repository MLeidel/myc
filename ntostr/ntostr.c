//ntostr.c
#include "../myc.h"
/***
* converting numbers to strings
* for both automatic and dynamic memory variables
* counter parts for:
*   atoi, atol, atof
*
* with decimal precision and thousands separator options
*
* intstr and intstr_new
* lngstr and lngstr_new
* dblstr and dblstr_new
***/

double n_dbl = 12323423342.123 / 3;
long n_lng = 23432343;
int n_int = 1232;
char snum[128]; // buffer to hold some results



void main (int argc, char *argv[]) {

    puts(intstr(snum, n_int, true));  // automatic memory

    char *pnum = intstr_new(n_int, false);  // dynamic memory
    puts(pnum);
    free(pnum);

    puts(lngstr(snum, n_lng, false));  // automatic memory

    char *qnum = lngstr_new(n_lng, true);  // dynamic memory
    puts(qnum);
    free(qnum);

    puts(dblstr(snum, n_dbl, 2, true));  // automatic memory

    char *rnum = dblstr_new(n_dbl, 3, false);  // dynamic memory
    puts(rnum);
    free(rnum);

}
