// urlencode.c
#include "../myc.h"

/*
   test:
   "?key=val1&key=first middle last"

   Output:
   %3fkey%3dval1%26key%3dfirst%20middle%20last
*/
void main() {
   char querystring[] = "?key=value;client=First Middle Last";
   char encoded[64] = {'\0'};

   urlencode(encoded, querystring);

   puts(encoded);
   // output: %3fkey%3dvalue%3bclient%3dFirst%20Middle%20Last


}