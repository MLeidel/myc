// trim.c
#include "../myc.h"


int main (int argc, char *argv[]) {

    char line[] = "  abc\t Hello  \r\n";

    char *l = line;

    printf("\noriginal line: [%s]\n\n", l);

    printf("trim: [%s]\n\n", trim(l));
    strcpy(line, "  abc\t Hello  \n"); // back to original string
    printf("rtrim: [%s]\n\n", rtrim(l));
    strcpy(line, "  abc\t Hello  \n"); // back to original string
    printf("ltrim: [%s]\n\n", ltrim(l));


    return 0;
}
