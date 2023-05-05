#include "../myc.h"

/* Use care in how you declare string literals
*/

int main(int argc, char const *argv[])
{
    char * p = "Lorem ipsum dolor sit amet, consectetur adipiscing elit";

    char * q[] = {"Lorem ipsum dolor sit amet", "consectetur adipiscing elit"};

    char r[][50] = {"Lorem ipsum dolor sit amet", "consectetur adipiscing elit"};

    char s[] = "sunt in culpa qui officia deserunt mollit anim id est laborum";

    const char t[] = "sunt in culpa qui officia deserunt mollit anim id est laborum";


    // *(p+3) = 'X';       // Segmentation fault
    printf("%s\n", p);

    // *(q[0]+3) = 'X';    // Segmentation fault
    printf("%s\n", q[0]);

    *(r[0]+3) = 'X';    // OK
    printf("%s\n", r[0]);

    *(s+3) = 'X';       // OK
    printf("%s\n", s);

    // *(t+3) = 'X';       // error: assignment of read-only location
    printf("%s\n", t);


/***
The best way to declare a string literal in your code is
to use array notation, like this:

    char string[] = "I am some sort of interesting string.\n";

This type of declaration is 100 percent okey-doke.
The compiler allocates proper storage for the string,
including the null character at the end,
and it assigns it to the array string. Nifty keen.

You can also declare a string in this manner (not as good):

    char *string = "I am some sort of interesting string.\n";

Again, in the code you can use the string variable
to reference the text — but that’s about it.
Altering the string or passing it to a function renders heaps of trouble.
So, while you effectively create a string,
you pretty much doom your code not to do anything with the string.
***/
}
