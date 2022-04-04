// wraplines.c
#include "../myc.h"


/*
    Reformats lines of text to all have a new line width
    where lines are separated on word boundaries
*/

char lines[] = "Lorem ipsum dolor sit amet,\nconsectetur adipiscing elit,\nsed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.";

void main (int argc, char *argv[]) {

    string wrapped = string_wrp(lines, 30, '\n');
    puts(wrapped.value);
    printf("allocated: %ld\n", wrapped.length);
    string_del(wrapped);
}
