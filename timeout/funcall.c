#include <stdio.h>

void print();
void execute(void(int));

int main()
{
    execute(print); // sends address of print
    return 0;
}

void print(int x)
{
    printf("%d Hello\n", x);
}

void execute(void f(int)) // receive address of print
{
    f(3);
}
