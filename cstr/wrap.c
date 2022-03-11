// wraplines.c
#include "../myc.h"


/*
    cstr_wrp reformats lines of text to all have a new line width
    where lines are separated on word boundaries
*/

char lines[] = "Lorem ipsum dolor sit amet,\nconsectetur adipiscing elit,\nsed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.";

void main (int argc, char *argv[]) {

    cstr wrapped = cstr_wrp(lines, 30, '\n');
    puts(wrapped.str);
    printf("allocated: %ld\n", wrapped.length);
    cstr_del(wrapped);
}
