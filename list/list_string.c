// list_string.c
// #include <myc.h>
#include "../myc.h"


void main () {
    char buf[350] = {'\0'};

    list csvstr = list_def(7, 32);

    list_init(csvstr,
        "Mike Johnson",
        "69,123.22",
        "101 Technology Ave, 53186",
        "53217",
        "69.70",
        "Pewaukee",
        "$22.81");

    puts(list_string(csvstr, buf, ","));

    list_del(csvstr);

    printf("123.22 -> %d\n", isnum_us("123.22"));
    printf("$123.22 -> %d\n", isnum_us("$123.22"));
    printf("12322 -> %d\n", isnum_us("12322"));
    printf(" 123.22  -> %d\n", isnum_us(" 123.22 "));
    printf(".12322 -> %d\n", isnum_us(".12322"));
    printf("12,322 -> %d\n", isnum_us("12,322"));
    printf("11,112,322 -> %d\n", isnum_us("11,112,322"));

}
