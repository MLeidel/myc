// trim.c
#include "../myc.h"

char *_ltrim(char *s) {
    char *forward = s;
    while(isspace(*forward++));
    return forward-1;
}

char *_rtrim(char *s) {
    char* back = s + strlen(s);
    while(isspace(*--back));
    *(back+1) = '\0';
    return s;
}

char *_trim(char *s) {
    return _rtrim(_ltrim(s));
}


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
