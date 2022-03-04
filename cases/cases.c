// cases.c
#include "../myc.h"


int main (int argc, char *argv[]) {
    
    char lorum[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.";

    puts(lorum);
    uppercase(lorum);
    puts(lorum);
    lowercase(lorum);
    puts(lorum);
    return 0;
}
