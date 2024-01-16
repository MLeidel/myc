/*
Returns true if file is binary and not plain text
*/

#include <myc.h>


// bool isbinary(char *filename) {
//     FILE *file = fopen(filename, "r");

//     if (file == NULL) {
//         printf("Error opening file: %s\n", filename);
//         exit(EXIT_FAILURE);
//     }

//     int ch;
//     while ((ch = fgetc(file)) != EOF) {
//         if (ch == NULL) {
//             fclose(file);
//             return true;
//         }
//     }

//     fclose(file);
//     return false;
// }



int main(int argc, char *argv[]) {

    if (isbinary(argv[1])) {
        puts("Binary File");
    } else {
        puts("Plain Text");
    }

    return 0;
}
