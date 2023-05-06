//color.c
// #include <myc.h>
#include "../myc.h"

void main (int argc, char *argv[]) {

    printf("%s this is red.\n", clr_fg.red);
    printf("%s this is green.\n", clr_fg.green);
    printf("%s this is blue.\n", clr_fg.blue);
    printf("%s this is dark blue.\n", clr_fg.dark_blue);
    printf("%s this is dark green.\n", clr_fg.dark_green);
    printf("%s this is yellow.\n", clr_fg.yellow);
    printf("%s this is dark yellow.\n", clr_fg.dark_yellow);

    puts(clr_fg.black);

    printf("%s this is red background.\n", clr_bg.red);
    printf("%s this is gray background.\n", clr_bg.light_gray);
    printf("%s this is blue background.\n", clr_bg.blue);
    printf("%s this is dark green background.\n\n", clr_bg.green);

    printf("%s%s this is darkBlue on White.\n", clr_bg.white, clr_fg.dark_blue);
    printf("%s%s this is darkRed on darkGreen.\n", clr_bg.dark_red, clr_fg.dark_green);
}

