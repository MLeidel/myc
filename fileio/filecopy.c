// filecopy.c
#include "../myc.h"

/* EXAMPLES

    filecopy, filemove, filedelete

    filemove uses both filecopy and filedelete
*/

void main (int argc, char *argv[]) {
    char f1[512];
    char f2[512];

    zenfile(f1, ".", false);
    puts(f1);
    zenfile(f2, ".", true);
    puts(f2);

    if(file_exists(f2)) {
        if(zenmsg("Exists", "Overwrite Destination file?", "question") == ZENMSG_YES)
            filemove(f1, f2);
    } else {
        filemove(f1, f2);
    }
}
