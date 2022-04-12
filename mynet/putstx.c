#include <myc.h>
#include <mynet.h>

/*
  send "startmemo.txt" to server (upstart.php)
*/

char netpath[] = "https://xxxxxxxxxxxxxxxxxxxxxxxxxxx/upstart.php";

char* prep_keyvalue(char *buf, char *key, char *value) {
    // prepares a key-value string to send over http...
    string coded = string_def(4096, '\0');
    strcpy(buf, key);
    strcat(buf, urlencode(coded.value, value));
    string_del(coded);
    return buf;
}


void main (int argc, char *argv[]) {

    string content = string_def(4096, '\0');
    string     dat = string_def(4096, '\0');

    // get file content
    readfile (content.value, "startmemo.txt");
    prep_keyvalue(dat.value, "data=", content.value);
    string_del(content);

    // post to server
    if (!webpost(netpath, dat.value)) {
      printf("exiting because of webpost failure\n");
      exit(1);
    } else {
      printf("webpost success!\n");
    }
    string_del(dat);
}
