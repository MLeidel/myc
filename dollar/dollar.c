// dollar.c
#include "../myc.h"

/*
    char *dollar(char *space, double amount, int fsize, int type)
    type: 1 = no $ and no separator
    type: 2 = yes $ and no separator
    type: 3 = yes $ and yes separator
*/

void main () {

    char buff[128] = {'\0'};

    printf("[%s]\n", dollar(buff, 31102.56, 15, 0));
    printf("[%s]\n", dollar(buff, 31102.56, 15, 1));
    printf("[%s]\n", dollar(buff, 31102.56, 15, 2));

}

/* OUTPUT
[       31102.56]
[      $31102.56]
[     $31,102.56]
*/