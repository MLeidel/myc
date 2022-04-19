// getbase.c
#include <myc.h>

/*
    parse out different parts of a filepath
    "file.txt"
    1 - getfullpath -> /home/user/file.txt
    2 - getbasename (with or without extension) -> file or file.txt
    3 - getbasepath -> /home/user
*/


void main (int argc, char *argv[]) {
    char buff[4096] = {'\0'};
    char path1[] = "testfile.txt";
    char path2[] = "testfile";
    char path3[] = "/home/user/testfile.txt";
    char path4[] = "/home/user/testfile";

    puts(path1);
    puts(path2);
    puts(path3);
    puts(path4);

    puts("-------with extension----------");
    puts(getbasename(path1, true));
    puts(getbasename(path2, true));
    puts(getbasename(path3, true));
    puts(getbasename(path4, true));
    puts("-------without extension----------");
    puts(getbasename(path1, false));
    puts(getbasename(path2, false));
    puts(getbasename(path3, false));
    puts(getbasename(path4, false));

    puts("-------getfullpath---------");

    puts(realpath("getbase.c", buff));
    puts(getfullpath("getbase.c", buff));

    puts("-------getbasepath---------");

    puts(getbasepath("getbase.c", buff));

    puts("- - - -");

    getfullpath("testfile.txt", buff);
    puts(getbasename(buff, false));
}
