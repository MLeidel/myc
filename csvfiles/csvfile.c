/***
* demo using list functions from myc.h
* calculate an average using a column
* from a 100000 record csv file
***/
#include "../myc.h"

// enum not necessary but adds to readability
enum cols {sno,Year,Month,Date,Reason,Education,Sex,Age,Race,Hispanic,Location,Police};

int main (int argc, char *argv[]) {
    char line[1024] = {"\0"};
    int counter = 0;
    double accum = 0.0;

    list csv = list_def(12, 64);  // malloc mem to hold fields

    FILE * f = open_for_read("guns.csv");
    while(!feof(f)) {
        fgets(line, 1024, f);
        rtrim(line);

        list_split(csv, line, ",");  // parse out the trimmed fields

        counter++;
        accum += atoi(csv.item[Age]);  // use field 7 "age"
    }
    fclose(f);

    list_del(csv);  // free list array memory

    printf("records read: %d\n", counter);
    printf("Avg age to die by gun violence: %0.2f\n", (double)accum/counter);

    return 0;
}