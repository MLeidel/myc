// fcsvinfo.c
#include "../myc.h"

/** fcsvinfo function
* find the num lines, num cols, longest field and line in a csv file
* function to obtain csv file info returns a struct csvinfo
* csvinfo(filename, delimiter, bool heading)
***/

void display(csvinfo s, char *filename) {
    // display results to console
    printf("\ncsvinfo for: %s\n", filename);
    printf("Lines: %ld\n", s.lines);
    printf("Columns: %ld\n", s.columns);
    printf("Max Line Length: %ld\n", s.max_line);
    printf("Max column Length: %ld\n", s.max_column);
}


void main () {

    csvinfo s = fcsvinfo("test.csv", ",", true);
    display(s, "test.csv");

    s = fcsvinfo("spaceship.csv", ",", true);
    display(s, "spaceship.csv");
}

/* OUTPUT

csvinfo for: test.csv
Lines: 60
Columns: 13
Max Line Length: 79
Max column Length: 30

csvinfo for: spaceship.csv
Lines: 55
Columns: 14
Max Line Length: 104
Max column Length: 18

*/
