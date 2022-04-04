// list_read.c
#include "../myc.h"


/*
             _  _   __   __  __ _
            ( \/ ) / _\ (  )(  ( \
            / \/ \/    \ )( /    /
            \_)(_/\_/\_/(__)\_)__)
 */

void main (int argc, char *argv[]) {

    list flst = list_read("test.txt", false);
    list_display(flst);
    list_del(flst);
}
