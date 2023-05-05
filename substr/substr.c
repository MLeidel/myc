// c substr routime
#include "../myc.h"


/* substr
   param:
   1> pointer to substring storage which is returned
   2> original (input) string
   3> staring position in input string
   4> length of substring to extract

*/


void main() {
   char s[64] = "Hello Sublime Text";
   char data[64];

   printf("\n%s\n", substr(data, s, 6, 0));  // Sublime Text

   printf("%s\n", substr(data, s, 6, 7));   // Sublime

   substr(data, s, 0, 13);
   printf("%s\n", data); // Hello Sublime

   puts(s);

   printf("%s\n\n", substr(data, s, 13, 8));  // program aborts - out of bounds
}

/*
OUTPUT:

Sublime Text
Sublime
Hello Sublime
Hello Sublime Text
ERRMSG  ../myc.h near line: 1508, errno: -1 application defined
substr inputs out of bounds
Program Exited

*/