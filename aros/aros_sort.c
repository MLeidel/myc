// aros_sort.c
#include "../myc.h"


int main (int argc, char *argv[]) {

    #define COLS 5
    char ary[] = "Sort this list, kefer, 123.55, poe, Edgar";

    printf("%s\n\n", ary);

    puts("========list before sorting=========");

    aros list = aros_new(COLS, 32);

    aros_parse(list, ary, ",");

    aros_display(list);

    puts("========sort and ignore case=========");

    ssort(list.item, COLS, true);

    aros_display(list);

    puts("=======sort and case sensitive=======");

    ssort(list.item, COLS, false);

    aros_display(list);


    aros_del(list);

    return 0;
}
