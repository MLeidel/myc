// example.c
#include "../myc.h"

/***
* Replaces one char with another char.
* Can adjest starting point and limit
* replacements.
***/

void main() {

    int c = 0;
    char line[] = "abcd abcd abcd";

    c = replacechar(line, 'a', 'A', 0);
    puts(line);  // Abcd Abcd Abcd

    c = replacechar(line+5, 'd', '7', 1);
    puts(line);  // Abcd Abc7 Abcd

 }