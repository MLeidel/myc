// padding.c
#include "../myc.h"

/*
    char *lpad(char *buff, char *str, char *filler, int n)
    n = repetitions of filler
*/

void main (int argc, char *argv[]) {

    char buff[128] = {'\0'};  // to store results

    printf("[%s]\n",lpad(buff, "hello", " ", 10));
    printf("[%s]\n",rpad(buff, "hiya", " ", 10));
    printf("[%s]\n",lpad(buff, "hello", "<>", 3));

    puts("\nUsed in 'dollar' function:\n");

    printf("[%s]\n", dollar(buff, 31102.56, 15, 0));
    printf("[%s]\n", dollar(buff, 31102.56, 15, 1));
    printf("[%s]\n", dollar(buff, 31102.56, 15, 2));

    // segfault
    printf("[%s]\n",rpad(buff, "hellooooo", "O", 600));

}

/* OUTPUT
[          hello]
[hiya          ]
[<><><>hello]
[helloooooOOOOOO]

Used in 'dollar' function:

[       31102.56]
[      $31102.56]
[     $31,102.56]
*/