//color.c
// #include <myc.h>
#include "../myc.h"

struct Clr {
    char dft[10];
    char black[10];
    char dark_red[10];
    char dark_green[10];
    char dark_yellow[10];
    char dark_blue[10];
    char dark_magenta[10];
    char dark_cyan[10];
    char light_gray[10];
    char dark_gray[10];
    char red[10];
    char green[10];
    char yellow[10];
    char blue[10];
    char magenta[10];
    char cyan[10];
    char white[10];
};
struct Clr clr_fg = {"\033[39m",
                    "\033[30m",
                    "\033[31m",
                    "\033[32m",
                    "\033[33m",
                    "\033[34m",
                    "\033[35m",
                    "\033[36m",
                    "\033[37m",
                    "\033[90m",
                    "\033[91m",
                    "\033[92m",
                    "\033[93m",
                    "\033[94m",
                    "\033[95m",
                    "\033[96m",
                    "\033[97m"};
struct Clr clr_bg = {"\033[49m",
                    "\033[40m",
                    "\033[41m",
                    "\033[42m",
                    "\033[43m",
                    "\033[44m",
                    "\033[45m",
                    "\033[46m",
                    "\033[47m",
                    "\033[100m",
                    "\033[101m",
                    "\033[102m",
                    "\033[103m",
                    "\033[104m",
                    "\033[105m",
                    "\033[106m",
                    "\033[107m"};

void main (int argc, char *argv[]) {

    printf("%s this is red.\n", clr_fg.red);
    printf("%s this is green.\n", clr_fg.green);
    printf("%s this is blue.\n", clr_fg.blue);
    printf("%s this is dark green.\n", clr_fg.dark_green);

    puts(clr_fg.black);

    printf("%s this is red background.\n", clr_bg.red);
    printf("%s this is gray background.\n", clr_bg.light_gray);
    printf("%s this is blue background.\n", clr_bg.blue);
    printf("%s this is dark green background.\n", clr_bg.green);

    printf("%s%s this is darkBlue on Red.\n", clr_bg.red, clr_fg.dark_blue);
    printf("%s%s this is darkRed on darkGreen.\n", clr_bg.dark_red, clr_fg.dark_green);

}

