#include "../myc.h"



int main(int argc, char const *argv[])
{
    char * s = "Lorem ipsum dolor sit amet, consectetur adipiscing elit";

    puts("vvvvvvvvv10vvvvvvvv20vvvvvvvv30vvvvvvvv40vvvvvvvv50vvvvv");
    puts(s);

    printf("charat 'r' found at: %i\n", charat(s, 'r'));

    printf("lastcharat 'r' found at: %i\n", lastcharat(s, 'r'));

    printf("indexof 'ipsum' found at: %i\n", indexof(s, "ipsum"));

    printf("lastindexof of 'et' found at: %i\n", lastindexof(s, "et"));

}