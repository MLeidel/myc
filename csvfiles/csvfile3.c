/***
* demo using list functions from myc.h
* calculate an average using a column
* from a 100000 record csv file
***/
#include "../myc.h"

int main (int argc, char *argv[]) {
    char line[1024] = {"\0"};
    int counter = 0;
    double accum = 0.0;

    // create structure of type list and allocate memory to hold fields
    list csv = list_def(12, 64);

    FILE * f = open_for_read("guns.csv");
    while(!feof(f)) {
        fgets(line, 1024, f);
        rtrim(line);

        list_split(csv, line, ",");  // parse out the trimmed fields

        counter++;
        accum += atoi(csv.item[7]);  // use field[7] "age"

        /* Test to open multiple lists
        */
        if (counter == 100) {
            char mylist[] = "\"E. Musk, CEO, Founder\",10012,\"Tesla V8\", 89123.44, \"Cincinati, OH\",11,43, 50";
            char out[32];
            double total = 0.0;
            char *eptr;

            printf("%s\n", mylist);

            list lst = list_def(8, 64);

            list_split(lst, mylist, ",");

            list_display(lst);

            puts("remove double quotes ...");
            for(int x = 0; x < lst.nbr_rows; x++) {
                printf("%d - [%s]\n", x, deletechar(out, lst.item[x], "\"", 0, 0));
            }

            for(int x = 5; x < 8; x++) {
                total = strtod(lst.item[3], &eptr) * atoi(lst.item[x]);
                printf("field %d amount: %.2f\n", x, total);
            }

            list_del(lst);
        }

    }
    fclose(f);

    list_del(csv);  // free array_of_strings memory

    printf("records read: %d\n", counter);
    printf("Avg age to die by gun violence: %0.2f\n", (double)accum/counter);

    return 0;
}

