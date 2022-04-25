// list_redef.c
// #include <myc.h>
#include "../myc.h"



void main (int argc, char *argv[]) {
    int x = 0;
    list lst = list_def(5, 32);

    list_init(lst, "Entry zero",
                   "Entry ONE",
                   "2 2 2 2 2",
                   "Three Two One Zero",
                   "ffoouurr");

    list_display(lst);

    puts("\nadding two more rows ...\n");

    lst = list_redef(lst, 7, 32);

    list_update(lst, "added 1 after redef", 5);
    list_update(lst, "added 2 after redef", 6);

    list_display(lst);

    list_del(lst);
}

/* OUTPUT
000 - [Entry zero]
001 - [Entry ONE]
002 - [2 2 2 2 2]
003 - [Three Two One Zero]
004 - [ffoouurr]

adding two more rows ...

000 - [Entry zero]
001 - [Entry ONE]
002 - [2 2 2 2 2]
003 - [Three Two One Zero]
004 - [ffoouurr]
005 - [added 1 after redef]
006 - [added 2 after redef]
*/