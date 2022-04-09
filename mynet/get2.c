// get2.c
#include <myc.h>
#include "mynet.h"

// using "sprintf"


void main () {

    char *dat = malloc(4096);
    char *wrk = malloc(4096);

    sprintf(dat, "%s%s%s%s%s", "https://someprocess.php",
                   "?data=",
                   urlencode(wrk, "1st-key is data"),
                   "&var=",
                   urlencode(wrk, "2nd-key is 'var'...")
                   );

    if (!webget(dat)) {
      printf("webget failed\n");
      exit(EXIT_FAILURE);
    } else {
      printf("webget success!\n");
    }
}
