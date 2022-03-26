// strcmp.c
#include <myc.h>


void main (int argc, char *argv[]) {

    if (argc < 3) {
       printf("Missing Arguments\n");
       exit(EXIT_FAILURE);
    }

    printf("%s  %s  %d\n", argv[1], argv[2], strcmp(argv[1], argv[2]));

}
