// contains.c
#include "../myc.h"


void main() {

char line[] = "sed do, \"eiusmod, tempor\", incididunt, ut labore";

    printf("%d\n", contains(line, "id"));   // 2
    printf("%d\n", contains(line, "e"));  // 4

    printf("%d\n", contains(line, ","));  // 4

    printf("%d\n", contvars(line, ","));  // 4

}
