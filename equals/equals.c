// equals.c
#include "../myc.h"


int main () {

    char line1[] = "pariatur.\n";
    char line2[] = "Pariatur.\n";

// ONLY FOR STRINGS NOT NUMBERS or CHARacters

    if (equals(line1, line2)) {
        puts("yup!");
    } else {
        puts("nope!");  // this
    }

    if (equalsignore(line1, line2)) {
        puts("yup!");  // this
    } else {
        puts("nope!");
    }

    return 0;
}
