// urlencode.c
#include "../myc.h"


int main (int argc, char *argv[]) {

    if (argc < 2) {
       printf("Missing url\n");
       exit(1);
    }

    puts(urlencode(argv[1]));

    return 0;
}
