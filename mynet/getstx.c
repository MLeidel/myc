#include <myc.h>
#include <mynet.h>

/*
  retrieve "startmemo.txt" from server
*/

char netpath[] = "https://xxxxxxxxxxxxxxxxxxxxxxxxxxx/startmemo.txt";

void main() {

    string pagebuf = string_def(4096, '\0');
    if (!webpage(pagebuf.value, 4096, netpath)) {
      string_del(pagebuf);
      ERRMSG(-1, true, "exiting because of webpage failure");
    } else {
      printf("webpage success!\n");
      writefile (pagebuf.value, "startmemo.txt", false);
      string_del(pagebuf);
    }
}
