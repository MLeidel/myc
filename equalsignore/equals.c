// equals.c
#include "../myc.h"


int main (int argc, char *argv[]) {

    char line1[] = "pariatur.\n";
    char line2[] = "Pariatur.\n";


    if (equals(line1, line2)) {
        puts("yup!");
    } else {
        puts("nope!");
    }

    if (equalsignorecase(line1, line2)) {
        puts("yup!");
    } else {
        puts("nope!");
    }

    return 0;
}
