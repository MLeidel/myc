// post1.c
#include "../myc.h"
#include "mynet.h"

void main (int argc, char *argv[]) {

    char buf1[50000];
    char *buf2 = malloc(50000);

    int rc = readfile(buf1, "textfile.txt");
    urlencode(buf2, buf1); // urlencode the content part(s)
    concat(buf1, 2, "data=", buf2);
    free(buf2);

    if (!webpost("https://someprocess.php", buf1)) {
        printf("exiting because of webpost failure\n");
        exit(1);
    } else {
        printf("webpost success!\n");
    }
}
