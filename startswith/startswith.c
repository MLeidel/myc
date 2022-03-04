// endswith.c
#include "../myc.h"


int main (int argc, char *argv[]) {

    char line[] = "Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur.\n";


    if (startswith(line, "duis\n")) {
        puts("yup!");
    } else {
        puts("nope!");
    }

    return 0;
}
