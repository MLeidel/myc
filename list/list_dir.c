// list_dir.c
#include "../myc.h"

int main (int argc, char *argv[]) {

    list d = list_dir("/home/ml/", 1, true);
    list_display(d);
    list_del(d);

    return 0;
}
