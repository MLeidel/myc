// errmsg.c
#include "../myc.h"

#define MAX_L 4096  // used a lot for default string lengths
#define ARRSIZE(x)  (sizeof(x) / sizeof((x)[0]))
#define ERRMSG(a, b, c) (errmsg(a, b, c, __LINE__))


void main () {

    ERRMSG(-1, false, "my message");
    ERRMSG(1, true, "Again my message.");

}
