#include <myc.h>
#include "mynet.h"

/*
Demos "webpage" and "webbrowser" functions
*/

char *get_page_title(char *buf, char *url) {
    const size_t bufsize = 1000000; // buffer to hold page html content
    // use 'webpage' to get the pages <title> text
    string pagebuf = string_def(bufsize, '\0');
    if (!webpage(pagebuf.value, bufsize, url)) {
      ERRMSG(-1, true, "get_page_title: webpage failure\n");
    } else {
      // puts(pagebuf.value);
      int p = between(buf, pagebuf.value, "<title>", "</title>", 0);
      if(p == -1) {
        ERRMSG(-1, true, "get_page_title: could not find title tag");
      }
    }
    string_del(pagebuf);
    return buf;
}


void main() {
    char title[120] = {'\0'};

    puts(get_page_title(title, "https://example.com"));

    if (!webbrowser("https://example.com")) {
      printf("webbrowser failure\n");
    } else {
      printf("webbrowser success!\n");
    }

}
/* OUTPUT
Example Domain
webbrowser success!
*/
