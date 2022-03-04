// makestr.c
#include "../myc.h"

char *makestr(int size, char* init) {
    char *p = malloc(size);
    strcpy(p, init);
    return p;
}

void freestr(char* ptr) {
    free(ptr);
    ptr = NULL;
}

int main (int argc, char *argv[]) {

    char *str = makestr(1000, "Hello Mary Elizabeth Smith");

    puts(str);

    freestr(str);

    return 0;
}
