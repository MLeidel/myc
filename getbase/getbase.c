// getbase.c
#include <myc.h>

/*
    parse out different parts of a filepath
    "file.txt"
    1 - getfullpath -> /home/user/file.txt
    2 - getbasename (with or without extension) -> file or file.txt
    3 - getbasepath -> /home/user
*/


// /*
//   just a "replay" of realpath function
// */
// char *getfullpath(char *fn, char *buff) {
//     return realpath(fn, buff);
// }

// char* getbasename(char *fn, bool withext) {
//     char *s = strrchr(fn, '/');  // find the last "/" in the path
//     char *p = strrchr(fn, '.');  // last "." in path

//     if (withext) {  // WITH extension

//         if (s == NULL) { // no path present
//             return fn;   // already base - nothing to do
//         } else {         // path present
//             return ++s;  // return past end of path/
//         }

//     } else {  // WITHOUT extension

//         if (s == NULL) {     // no path present
//             if (p == NULL) { // no ext present
//                 return fn;   // already base & no ext - nothing to do
//             } else {         // ext is present
//                 *p = '\0';   // cut off extension at '.'
//                 return fn;
//             }
//         } else {             // path present
//             if (p == NULL) { // no no extension present
//                 return ++s;  // already base & no ext - nothing to do
//             } else {
//                 *p = '\0';   // cut off extension at '.'
//                 return ++s;
//             }
//         }
//     }
// }

// char *getbasepath(char *fn, char *buff) {
//     realpath(fn, buff);
//     char *s = strrchr(buff, '/');  // find the last "/" in the path
//     if (s != NULL) {
//         *s = '\0';
//     }
//     return buff;
// }



void main (int argc, char *argv[]) {
    char buff[MAX_L];
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
