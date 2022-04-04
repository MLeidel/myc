// string.c
#include "../myc.h"

/*
        STRINGS
*/


void main (int argc, char *argv[]) {

    string s = string_def(32, '\0');

    string_cpy(s, "Hello World");

    puts(s.value);

    string_del(s);

    ////////////////////////////

    string str = string_new("Hello Universe");

    puts(str.value);

    string_del(str);

    ////////////////////////////

    string s1 = string_new("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.");

    string ss = string_wrp(s1.value, 35, '\n');

    puts(ss.value);

    string_del(s1);
    string_del(ss);

}
