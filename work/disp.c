// disp.c
#include "../myc.h"

void print(char *data)
{
    puts(data);
}

void helloworld(void (*f)(char*))
{
    f(char*);
}

int main(void)
{
    helloworld(print("Hello"));
    return (0);
}
