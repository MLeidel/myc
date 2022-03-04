#include "../myc.h"


int main()
{
    char * s = "Lorem ipsum dolor sit amet, consectetur adipiscing elit";


    char *p;


    p = strchr(s, 'm');

    printf("s found at: %p\n", s);
    printf("first 'm' found at: %p\n", p);
    printf("index of 'm' found at: %li\n", p - s);

    printf("charat of 'm' fount at: %i\n", charat(s, 'm'));

    return 0;
}