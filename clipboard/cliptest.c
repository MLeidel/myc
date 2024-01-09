// cliptest.c
// #include <myc.h>
#include "../myc.h"

/*
int cbcopy(char *text)     // copy to clipboard
char *cbpaste(char *text)  // paste from clipboard
*/

// int cbcopy(char *text) {
//     /* copies text to the system clipboard
//     usint xclip command */
//     char cmd[10240]; // 10K
//     int rc = 0;

//     sprintf(cmd, "echo \"%s\" | xclip -selection clipboard", text);
//     rc = system(cmd);
//     return rc;
// }

// char *cbpaste(char *text) {
//     /* pastes clipboard into text */
//     char cmd[64]; // 10K

//     strncpy(cmd, "xclip -o", 10);
//     runproc(text, cmd);
//     chomp(text);
//     return text;
// }


void main (int argc, char *argv[]) {

    char txt[10240] = "put this into system clipboard";

    //cbcopy(txt);

    puts(cbpaste(txt));

}
