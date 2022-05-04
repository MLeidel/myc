// errmsg.c
#include "../myc.h"


void main () {

    long fs = filesize("abcdefg");

    printf("filesize returned: %ld\n\n", fs);

    ERRMSG(-1, false, "my message");
    ERRMSG(1, true, "Again my message.");

}
