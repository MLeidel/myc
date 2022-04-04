// list_init.c
#include "../myc.h"

void main () {

    list my_list = list_def(5, 32);

    list_init( my_list,
               "first string",
               "second string",
               "third string",
               "fourth string",
               "fifth string" );

    list_copy(my_list, 0, "F I R S T  STRING");
    list_copy(my_list, 4, "L A S T  STRING");

    list_display(my_list);
    list_del(my_list);
}