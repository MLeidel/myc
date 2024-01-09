// list_sort.c
#include "../myc.h"


void main () {

    char ary[] = "Sort this list, kefer, 123.55, poe, Edgar";

    printf("%s\n\n", ary);

    int cols = contvars(ary, ",");  // how many fields (values)

    puts("========list before sorting=========");

    list my_list = list_def(cols, 32);  // define a list

    list_split(my_list, ary, ",");  // load the list

    list_display(my_list);  // display the list

    puts("========sort and ignore case=========");

    ssort(my_list.item, my_list.nbr_rows, true);

    list_display(my_list);

    puts("=======sort and case sensitive=======");

    ssort(my_list.item, my_list.nbr_rows, false);

    list_display(my_list);


    list_del(my_list);

}

/*
Sort this list, kefer, 123.55, poe, Edgar

========list before sorting=========
000 - [Sort this list]
001 - [kefer]
002 - [123.55]
003 - [poe]
004 - [Edgar]
========sort and ignore case=========
000 - [123.55]
001 - [Edgar]
002 - [kefer]
003 - [poe]
004 - [Sort this list]
=======sort and case sensitive=======
000 - [123.55]
001 - [Edgar]
002 - [Sort this list]
003 - [kefer]
004 - [poe]
*/