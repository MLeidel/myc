// testgio.c
#include "../myc.h"
#include <gio/gio.h>

// has some memory leaks due to gio library

void main (int argc, char *argv[]) {

    if (argc < 2) {
       printf("Missing Argument\n");
       exit(1);
    }

    char fileToOpen [128] = {'\0'};
    GError *error = NULL;
    char *contents;
    gsize len;

    strcpy(fileToOpen, argv[1]);

    g_file_get_contents (fileToOpen, &contents, &len, &error);

    puts(contents);

    g_file_set_contents ("testgio_out.txt", contents, -1, &error);

    g_free(contents);
}
