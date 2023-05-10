// remove.c - editing the items of a list
#include "../myc.h"

void main (int argc, char *argv[]) {

    list hlist = list_def(10, 128);

    list_io(hlist, "remove.txt", 'r');
    list_display(hlist);

    if (argc > 2) { // if command present execute it ...
        if (equals(argv[1], "remove")) {
            list_remove(hlist, list_find(hlist, argv[2]));
            list_io(hlist, "entry_hist.txt", 'w');
        } else {
            ERRMSG(-1, true, "invalid command");
        }

        list_display(hlist);
    }
    list_del(hlist);
}
