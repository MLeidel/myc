// hist_lists.c
// #include <myc.h>
#include "../myc.h"

/*
    For a list of history items the current item is always pushed
    onto the top (0 zero) index. So then, to "go back" one increments
    the index to arrive at previous entries in the correct order (0,1,2,...).
    Conversly, to "go forward" one decrements the index towards the
    more recent entries in the correct order (2,1,0).
*/

#define HIST_SIZE 4

int move_index(int direction, int index) {
    if(direction == 0) { // (0) arrow UP "backwards"
        index++;
        if(index >= HIST_SIZE)
            index = 0;
    } else { // (1) arrow DOWN "forwards"
        index--;
        if(index < 0)
            index = 0; // Stop at most current
    }
    return index;
}


void main (int argc, char *argv[]) {

    char com[16] = {'\0'};
    int index = 0;
    list hist = list_def(HIST_SIZE, 32);
    list_init(hist, "zero",
                    "",
                    "",
                    "");

    while(1) {
        printf("Enter command: ");
        scanf("%s", com);
        if(equals(com, "quit")) break;
        if(equals(com, "next")) {
            index = move_index(1, index);
            printf("Next: %s\n", hist.item[index]);
            continue;
        }
        if(equals(com, "back")) {
            index = move_index(0, index);
            printf("Back: %s\n", hist.item[index]);
            continue;
        }
        if(equals(com, "show")) {
            list_display(hist);
            printf("at index: %d\n", index);
            continue;
        }
        list_inject(hist, com, 0);
        list_display(hist);
        index = HIST_SIZE - 1;
    }
    list_del(hist);
}
