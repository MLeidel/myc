// concat.c
#include "../myc.h"


int main (int argc, char *argv[]) {

    char s[MAX_L] = {'\0'};

    //strcpy(s, "Mrs. ");

    concat(s, 3, "Mary ", "Elizabeth ", "Smith");

    puts(s);

    return 0;
}
