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


    puts(dblstr(snum, 321321321.321 / 3, 2, true));  // automatic memory
    // 107,107,107.11

    double n_dbl = 123456789.101 / 3;
    char *rnum = dblstr_new(n_dbl, 4, false);  // dynamic memory
    puts(rnum);  // 41152263.0337
    free(rnum);

}
