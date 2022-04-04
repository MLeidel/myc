// list_sort.c
#include "../myc.h"


void main () {

    #define COLS 5
    char ary[] = "Sort this list, kefer, 123.55, poe, Edgar";

    printf("%s\n\n", ary);

    puts("========list before sorting=========");

    list my_list = list_def(COLS, 32);

    list_split(my_list, ary, ",");

    list_display(my_list);

    puts("========sort and ignore case=========");

    ssort(my_list.item, COLS, true);

    list_display(my_list);

    puts("=======sort and case sensitive=======");

    ssort(my_list.item, COLS, false);

    list_display(my_list);


    list_del(my_list);

}
