#include "../myc.h"

/* sorting array of double values
*/
double arr[] = {1.023, 1.22, 1.56, 2, 5, 3.331};

void printout(int s) {
    puts("\n\n");
    for(int x=0; x < s; x++) {
        printf("[%f]\n", arr[x]);
    }
}

int main() {

  printout(sizeof(arr)/sizeof(arr[0]));

  dsort(arr, ARRSIZE(arr));

  printout(sizeof(arr)/sizeof(arr[0]));

}

