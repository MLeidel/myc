// get1.c
#include <myc.h>
#include "mynet.h"

// using "concat"

void main () {

    char *dat = malloc(4096);
    char *wrk = malloc(4096);
    char *wr2 = malloc(4096);

    concat(dat, "https://someprocess.php",
                   "?data=",
                   urlencode(wrk, "1st-key is data"),
                   "&var=",
                   urlencode(wr2, "2nd-key is 'var'..."),
                   END);

    if (!webget(dat)) {
      printf("exiting because of webget failure\n");
      exit(EXIT_FAILURE);
    } else {
      printf("webget success!\n");
    }
    free(dat);
    free(wrk);
    free(wr2);
}
