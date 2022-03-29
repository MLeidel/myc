//printf.c
#include <myc.h>


void main (int argc, char *argv[]) {

    double d1 = 1232.3456;
    int i1 = 234;
    char s1[] = "Hello";


    printf("%.2f \n", d1);
    printf("%10.02f \n", d1);
    printf("%010.02f \n", d1);
    printf("%d \n", i1);
    printf("%010d \n", i1);
    printf("%-10s \n", s1);
    printf("%10s \n", s1);

    setlocale(LC_NUMERIC, "");
    printf("%'.2f \n", d1);
}
