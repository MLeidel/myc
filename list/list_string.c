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
/* VERSION JUST CHECKING FOR ALPHANUMERIC

char *list_string(list lst, char *str, char *delim) {
    int x = 0;
    int has_comma, has_space, has_apost, has_quote;
    char separator[8] = {'\0'};
    string sbuf = string_def(lst.nbr_rows * lst.len_rows + 1, '\0');

    strcpy(separator, delim);
    strcpy(str, "\0");

    for (x=0; x < lst.nbr_rows; x++) {
        has_comma = has_space = has_apost = has_quote = 0;
        has_comma = contains(lst.item[x], ",");
        has_space = contains(lst.item[x], " ");
        has_apost = contains(lst.item[x], "'");
        has_quote = contains(lst.item[x], "\"");
        if (x == lst.nbr_rows - 1)
            strcpy(separator, "\0"); // no delim on last item
        if (has_comma != 0 ||
            has_space != 0 ||
            has_apost != 0 ||
            has_quote != 0) {
            concat(str, "\"", lst.item[x], "\"", separator, END);
        } else {
            concat(str, lst.item[x], separator, END);
        }
        strcat(sbuf.value, str); // building the csv string
    }
    strcpy(str, sbuf.value);
    string_del(sbuf);
    return str;
}
*/
