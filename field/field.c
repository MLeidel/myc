/***
* field.c
* This is the newest version
*
***/
#include "../myc.h"

#define DELIM ','

void main() {

   char rec[] = "012320, Edgar Alan Poe, \"Raven, Black Cat, Pit\", American Author, Fiction";
   char data[100] = {"\0"};

   printf("\noriginal: %s\n\n", rec);

   field(data, rec, DELIM, 2, false );
   printf("%s\n", data);

   printf("%s\n", field( data, rec, DELIM, 0, true ));
   printf("%s\n", field( data, rec, DELIM, 4, false ));
   printf("%s\n", field( data, rec, DELIM, 2, true ));
   // remove double quotes ...
   printf("%s\n", trim(deletechar(data, data, '\"', 0)));

   printf("\noriginal: %s\n\n", rec);

   char * heap = calloc(100, sizeof(char));
   field(heap, rec, DELIM, 3, false );
   printf("%s\n", heap);
   free(heap);


}
