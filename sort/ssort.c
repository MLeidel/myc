#include "../myc.h"

char *strings[] = { "Zorro",
                    "Alex",
                    "Celine",
                    "Bill",
                    "Forest",
                    "Dexter",
                    "decimal man"};


void printout(int s) {
    puts("\n\n");
    for(int x=0; x < s; x++) {
        printf("%s\n", strings[x]);
    }
}


int main() {

  printout(ARRSIZE(strings));

  ssort(strings, ARRSIZE(strings), false);

  printout(ARRSIZE(strings));

  ssort(strings, ARRSIZE(strings), true);

  printout(ARRSIZE(strings));

}

