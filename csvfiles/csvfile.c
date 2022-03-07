/***
* demo using aros functions from myc.h
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

    aros csv = aros_new(12, 64);  // malloc mem to hold fields

    FILE * f = open_for_read("guns.csv");
    while(!feof(f)) {
        fgets(line, 1024, f);
        rtrim(line);

        aros_parse(csv, line, ",");  // parse out the trimmed fields

        counter++;
        accum += atoi(csv.get[Age]);  // use field 7 "age"
    }
    fclose(f);

    aros_del(csv);  // free aros array memory

    printf("records read: %d\n", counter);
    printf("Avg age to die by gun violence: %0.2f\n", (double)accum/counter);

    return 0;
}