// string.c

#include "../myc.h"

/*
Dynamic string allocation made easy.
The "string" struct is used for these functions:
*/

void main() {

    string s1 = string_def(255, '0');
    string s2 = string_def(255, '\0');
    string s3 = string_def(500, '\0');

    string_cpy(s1, "Lorem ipsum dolor sit amet, consectetur adipiscing elit, \
sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim \
ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip \
ex ea commodo consequat.");

    string_cpy(s2, "\nHello from The Man from U.N.C.L.E.\n");

    concat(s3.value, 2, s1.value, s2.value);

    puts(s3.value);

    string_del(s1);
    string_del(s2);
    string_del(s3);

/*
    Resize a string string
    string_rsz returns a new string pointer
    with reallocated size
*/

    string s = string_def(10, '\0');
    string_cpy(s, "Hello");
    puts(s.value);
    s = string_rsz(s, 20);
    //string_cpy(s, "Hello Universe");
    strcat(s.value, " Universe");
    puts(s.value);
    //string_del(s);

/*
    create a new dyamic string
*/

    string newstring = string_new("Hello World!");
    printf("%s - %ld\n", newstring.value, newstring.length);

    puts(s.value);

    string_del(s);
    string_del(newstring);

}
