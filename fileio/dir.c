// dir.c
#include "../myc.h"

int main (int argc, char *argv[]) {

    cary d = cary_dir("/home/ml/", 1, true);
    cary_display(d);
    cary_del(d);

    return 0;
}
