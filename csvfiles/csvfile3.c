/***
* demo using cary functions from myc.h
* calculate an average using a column
* from a 100000 record csv file
***/
#include "../myc.h"

int main (int argc, char *argv[]) {
    char line[1024] = {"\0"};
    int counter = 0;
    double accum = 0.0;

    // create structure of type cary and allocate memory to hold fields
    cary csv = cary_new(12, 64);

    FILE * f = open_for_read("guns.csv");
    while(!feof(f)) {
        fgets(line, 1024, f);
        rtrim(line);

        cary_parse(csv, line, ",");  // parse out the trimmed fields

        counter++;
        accum += atoi(csv.get[7]);  // use field[7] "age"

        /* Test to open multiple carys
        */
        if (counter == 100) {
            char mylist[] = "\"E. Musk, CEO, Founder\",10012,\"Tesla V8\", 89123.44, \"Cincinati, OH\",11,43, 50";
            char out[32];
            double total = 0.0;
            char *eptr;

            printf("%s\n", mylist);

            cary list = cary_new(8, 64);

            cary_parse(list, mylist, ",");

            cary_display(list);

            puts("remove double quotes ...");
            for(int x = 0; x < list.nbr_rows; x++) {
                printf("%d - [%s]\n", x, deletechar(out, list.get[x], '\"', 0));
            }

            for(int x = 5; x < 8; x++) {
                total = strtod(list.get[3], &eptr) * atoi(list.get[x]);
                printf("field %d amount: %.2f\n", x, total);
            }

            cary_del(list);
        }

    }
    fclose(f);

    cary_del(csv);  // free array_of_strings memory

    printf("records read: %d\n", counter);
    printf("Avg age to die by gun violence: %0.2f\n", (double)accum/counter);

    return 0;
}

