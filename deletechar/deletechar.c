// deletechar.c routime
#include "../myc.h"

void main() {

   char rec[] = "\"Edgar\",  Allan , Poe,, \"American Author\"";
   char data[100];

   printf("\noriginal: %s\n", rec);
   puts("=========================");

   printf("%s\n", deletechar(data, rec, '\"', 2));
                  // "Edgar,  Allan , Poe,, American Author"
   printf("%s\n", deletechar(data, rec, '\"', 0));
                  // Edgar,  Allan , Poe,, American Author
   deletechar(data, data, 'a', 0);
   puts(data);    // Edgr,  Alln , Poe,, Americn Author
   deletechar(data, data, 'o', 0);
   puts(data);    // Edgr,  Alln , Pe,, Americn Authr


   puts("=========================");
   printf("original: %s\n\n", rec);
}
