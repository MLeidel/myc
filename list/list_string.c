// list_string.c
// #include <myc.h>
#include "../myc.h"


/////////////////////////////////////////////////////////
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

    // optional remove items from the list
    //list_remove(csvstr, 4);  // 69.70 is deleted from list
    //list_remove(csvstr, 4);  // Pewaukee is deleted from list

    puts(list_string(csvstr, buf, "|", true));
    puts(list_string(csvstr, buf, "|", false));
    puts(list_string(csvstr, buf, ",", true));

    list_del(csvstr);

    puts("\n");
    printf("123.22 -> %d\n", isnum_us("123.22"));
    printf("$123.22 -> %d\n", isnum_us("$123.22"));
    printf("12322 -> %d\n", isnum_us("12322"));
    printf(" 123.22  -> %d\n", isnum_us(" 123.22 "));
    printf(".12322 -> %d\n", isnum_us(".12322"));
    printf("12,322 -> %d\n", isnum_us("12,322"));
    printf("11,112,322 -> %d\n", isnum_us("11,112,322"));

}
