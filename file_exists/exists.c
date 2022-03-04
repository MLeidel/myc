// exists.c
#include "../myc.h"


int main (int argc, char *argv[]) {

    if (file_exists("../test.csv")) {
        puts("yup!");  // yup!
    } else {
        puts("nope!");
    }

    /* isfile()
    */
    printf("%d\n", isfile("../test.csv"));       // 1
    printf("%d\n", isfile("../"));              //  0
    printf("%d\n", isfile("../abcdefg.xxx"));  //  -1

    return 0;
}
