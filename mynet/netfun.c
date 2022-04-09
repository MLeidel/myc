#include <myc.h>
#include "mynet.h"

/*
Demos "webpage" and "webbrowser" functions
*/

void main() {

    char *pagebuf;
    pagebuf = calloc(100000, sizeof(char*));
    if (!webpage(pagebuf, 100000, "https://someproc.php")) {
      printf("exiting because of webpage failure\n");
      free(pagebuf);
      exit(1);
    } else {
      printf("webpage success!\n%s\n", pagebuf);
      free(pagebuf);
    }



    if (!webbrowser("https://tekvow.net")) {
      printf("exiting because of webbrowser mynet.h failure\n");
      exit(1);
    } else {
      printf("webbrowser success!\n");
    }

}