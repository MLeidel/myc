// cary_sort.c
#include "../myc.h"


int main (int argc, char *argv[]) {

    #define COLS 5
    char ary[] = "Sort this list, kefer, 123.55, poe, Edgar";

    printf("%s\n\n", ary);

    puts("========list before sorting=========");

    cary list = cary_new(COLS, 32);

    cary_parse(list, ary, ",");

    cary_display(list);

    puts("========sort and ignore case=========");

    ssort(list.get, COLS, true);

    cary_display(list);

    puts("=======sort and case sensitive=======");

    ssort(list.get, COLS, false);

    cary_display(list);


    cary_del(list);

    return 0;
}
