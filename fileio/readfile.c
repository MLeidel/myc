// readfile.c
#include "../myc.h"

int main () {

    char data[50000];

    if (file_exists("urls.txt")) {
        readfile(data, "urls.txt");
        printf("\n%s\n", data);
    }


    return 0;
}
