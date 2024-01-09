/*
readini.c
*/

#include <myc.h>

void main(int argc, char *argv[]) {

    // Your code here
    list flst = list_read("test.ini", false);
    list_display(flst);
    list_del(flst);


}
