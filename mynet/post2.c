// post2.c
#include "../myc.h"
#include "mynet.h"

void main (int argc, char *argv[]) {

    char url[] = "https://someprocess.php";
    char *dat = malloc(MAX_L);
    char *wr1 = malloc(MAX_L);
    char *wr2 = malloc(MAX_L);

    // prepare querystring
    concat(dat, "data=",
                 urlencode(wr1, "content & ampersand!"),
                 "&var=",
                 urlencode(wr2, "second variable content!!!!"),
                 END);

    free(wr1);
    free(wr2);

    //puts(dat);

    // post to server
    if (!webpost(url, dat)) {
      printf("exiting because of webpost failure\n");
      exit(1);
    } else {
      printf("webpost success!\n");
    }
    free(dat);
}
