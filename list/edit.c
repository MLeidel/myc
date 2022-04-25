// edit.c - editing the items of a list
#include "../myc.h"
/*
    list_io
    list_inject
    list_remove
    list_find
    (list_update)


                    .__
       _____ _____  |__| ____
      /     \\__  \ |  |/    \
     |  Y Y  \/ __ \|  |   |  \
     |__|_|  (____  /__|___|  /
           \/     \/        \/
 */

void main (int argc, char *argv[]) {

    list hlist = list_def(10, 128);

    list_io(hlist, "entry_hist.txt", 'r');
    list_display(hlist);

    if (argc > 2) { // if command present execute it ...
        if (equals(argv[1], "inject")) {
            list_inject(hlist, argv[3], atoi(argv[2]));
            list_io(hlist, "entry_hist.txt", 'w');
        } else if (equals(argv[1], "remove")) {
            list_remove(hlist, list_find(hlist, argv[2]));
            list_io(hlist, "entry_hist.txt", 'w');
        } else if (equals(argv[1], "update")) {
            list_update(hlist, argv[3], atoi(argv[2]));
            list_io(hlist, "entry_hist.txt", 'w');
        } else {
            ERRMSG(-1, true, "invalid command");
        }

        list_display(hlist);
    } else {
        puts("\nuse: edit inject index item-text ");
        puts("or: edit remove item-text");
        puts("or: edit update index item-text");
    }

    list_del(hlist);
}
