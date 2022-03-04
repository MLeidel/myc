#include "../myc.h"

int arr[] = {4, 54, 11, 65, 456, 7, 1, 3, 5, 3, 4, 0, 121};


void printout(int s) {
    puts("\n\n");
    for(int x=0; x < s; x++) {
        printf("%d\n", arr[x]);
    }
}

int main() {

  printout(sizeof(arr)/sizeof(arr[0]));

  isort(arr, ARRSIZE(arr));

  printout(sizeof(arr)/sizeof(arr[0]));

}

