// concat.c
#include "../myc.h"

int main (int argc, char *argv[]) {

    char s[64] = {'\0'};

    concat(s, "Mary ", "Elizabeth ", "Smith", END);

    puts(s);

    return 0;
}
