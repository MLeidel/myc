#include "../myc.h"


void main()
{
    char * s = "Lorem ipsum dolor sit amet, consectetur adipiscing elit";

    printf("index of 'm' found at: %li\n", strchr(s, 'm') - s);  // index of 'm' found at: 4

    // find index of 'm' with charat
    printf("index of 'm' found at: %i\n", charat(s, 'm'));  //  index of 'm' found at: 4

}