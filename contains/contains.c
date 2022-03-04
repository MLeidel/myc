// contains.c
#include "../myc.h"

// int cont(char *s, char *targ) {
//     int tlen = strlen(targ);
//     int count = 0;
//     char *p = s;

//     while(true) {
//         p = strstr(p, targ);
//         if (p == NULL)
//             return count;
//         count++;
//         p += tlen;
//     }
// }


int main (int argc, char *argv[]) {

char line[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, \
sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, \
quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.";

    puts(line);

    printf("%d\n", contains(line, "co"));   // 4
    printf("%d\n", contains(line, "im"));  // 2
    printf("%d\n", contains(line, "o"));  // 18


    return 0;
}
