// deletechar.c routime
#include "../myc.h"


void main() {

   char rec[] = "\"Edgar\",  Allan , Poe,, \"American Author\"";
   char data[100];

   printf("\noriginal: %s\n", rec);
   puts("=========================");

   printf("%s\n", deletechar(data, rec, "\"", 12, 2));
                  // "Edgar",  Allan , Poe,, American Author
   printf("%s\n", deletechar(data, rec, "\"", 0, 2));
                  // Edgar,  Allan , Poe,, "American Author"
   deletechar(data, data, "Aaeiou\"", 0, 0);
   puts(data);    // Edgr,  lln , P,, mrcn thr
   deletechar(data, data, "Edgr, ", 0, 0);
   puts(data);    // llnPmcnth


   puts("=========================");
   printf("original: %s\n\n", rec);
}
