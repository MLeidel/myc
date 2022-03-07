// cstr.c

#include "../myc.h"

/*
Dynamic string allocation made easy.
The "cstr" struct is used for these functions:

typedef struct {
    size_t length;  // allocated length
    char *str;
} cstr;

*/



void main() {

    cstr s1 = cstr_new(255, '0');
    cstr s2 = cstr_new(255, '\0');
    cstr s3 = cstr_new(500, '\0');

    cstr_cpy(s1, "Lorem ipsum dolor sit amet, consectetur adipiscing elit, \
sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim \
ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip \
ex ea commodo consequat.");

    cstr_cpy(s2, "\nHello from The Man from U.N.C.L.E.\n");

    concat(s3.str, 2, s1.str, s2.str);

    puts(s3.str);

    cstr_del(s1);
    cstr_del(s2);
    cstr_del(s3);

/*
    Resize a cstr string
    cstr_rsz returns a new cstr pointer
    with reallocated size
*/

    cstr s = cstr_new(10, '\0');
    cstr_cpy(s, "Hello");
    puts(s.str);
    s = cstr_rsz(s, 20);
    //cstr_cpy(s, "Hello Universe");
    strcat(s.str, " Universe");
    puts(s.str);
    cstr_del(s);
}
