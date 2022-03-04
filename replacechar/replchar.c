
#include "../myc.h"

/***
* Replaces one char with another char.
* Can adjest starting point and limit
* replacements.
***/

int main()
{
    int c = 0;
    char line[] = "my, dog has flees,234,";
    char *p = line;

    printf("\n\n%s\n", line);

    c = replacechar(line, ',', '|', 0);
    printf("made %d replacements.\n", c);
    printf("%s\n\n", line);

    c = replacechar(line, '|', ';', 0);
    printf("made %d replacements.\n", c);
    printf("%s\n\n", line);

    c = replacechar(line, ';', ',', 2);
    printf("made %d replacements.\n", c);
    printf("%s\n\n", line);

    c = replacechar(p+=4, ',', '^', 1);  // start at +4 using pointer var addition
    printf("+4 made %d replacements.\n", c);
    printf("%s\n\n", p);

    c = replacechar(line, 'y', 'e', 0);
    printf("made %d replacements.\n", c);
    printf("%s\n\n", line);

    char lorum[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.";

    c = replacechar(lorum, 'i', 'I', 0);
    printf("made %d replacements.\n", c);
    printf("%s\n\n", lorum);

    replacechar(lorum, 'p', '\t', 0);
    printf("made %d replacements.\n", c);
    printf("%s\n\n", lorum);

    return 0;
}