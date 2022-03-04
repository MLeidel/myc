// chomp.c
#include "../myc.h"

int main (int argc, char *argv[]) {

    char line[] = "This is a line of text \r\n\r\n";

    printf("[%s]", line);

    chomp(line);
    // now chomp it
    //printf("[%s]", chomp(line));

    printf("[%s]\n", line);


    return 0;
}
