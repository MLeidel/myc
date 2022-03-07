// insert_new.c
#include "../myc.h"


/*
    insert_new

    Works line 'insert' but creates the new string
    at the exact new length.

    This is dynamic memory.
*/

void main() {

    char text[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit";
    puts(text);

    char *buf = insert_new(text, " amor", 26);
    puts(buf);  //Lorem ipsum dolor sit amet amor, consectetur adipiscing elit

    free(buf);
 }
