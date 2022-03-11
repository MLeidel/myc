// example.c
#include "../myc.h"


void main () {

    char mystr[32] = "Lorem ipsum dolor sit amet";

    char * newstr = replace_new(mystr,
                                "dolor",
                                "labore et dolore magna",
                                0,  // start
                                0); // how many
    printf("[%s] %ld\n", newstr, strlen(newstr));
    // [Lorem ipsum labore et dolore magna sit amet] 43

    free(newstr);
}
