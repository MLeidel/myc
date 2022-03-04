/***
* demo using getfield() function from myc.h
* calculate an average using a column
* from a 100000 record csv file
***/
#include "myc.h"

// enum not necessary but adds to readability
enum cols {Age = 7,
           Race,
           Hispanic};


int main (int argc, char *argv[]) {
    char line[1024] = {"\0"};
    char value[4];
    int counter = 0;
    int accum = 0;

    FILE * f = open_for_read("guns.csv");
    while(!feof(f)) {
        fgets(line, 1024, f);
        rtrim(line);

        counter++;
        accum += atoi(field(value, line, ',', Age, true));  // use field 7 "age"
    }
    fclose(f);

    printf("records read: %d\n", counter);
    printf("Avg age to die by gun violence: %0.2f\n", (double)accum/counter);

    return 0;
}