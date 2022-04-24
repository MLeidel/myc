// concat2.c
#include "../myc.h"

int main (int argc, char *argv[]) {

    char s[100] = {'\0'};

    string out = string_def(100, '\0');

    concat(s, "Mary ", "Elizabeth ", "Smith", END);

    strcat(out.value, s);

    concat(s, " and this", " also thissssssss.", END);

    strcat(out.value, s);

    puts(out.value);

    string_del(out);

    return 0;
}
