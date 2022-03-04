// byval.c  PASSING POINTERS
#include <stdio.h>
#include <string.h>

void func1(char val[9], int *x) {
  memset(val, 'Y', 8);
  *x = 1; // pointer to nbr
}

void func2(char val[9], int x) {
  memset(val, 'Z', 8);
  x = 2; // copy to nbr not a pointer
}

char *func3(char *val) {
  memset(val, '#', 8);
  return val;
}
char *func4(char *val) {
  memset(val, '@', 8);
  return val;
}

void main () {
  char wrk[9] = "XXXXXXXX";
  int nbr = 0;

  printf("%s %d\n", wrk, nbr);
  func1(wrk, &nbr); // strings pass pointers
  printf("%s %d\n", wrk, nbr);
  func2(wrk, nbr); // numbers need explicit syntax to pass pointers
  printf("%s %d\n", wrk, nbr);

  printf("%s %s\n", func3(wrk), func4(wrk));
    /*
    NOTE: printf used the local "copy" (pointer) of wrk from func3
    instead of using the altered value from func4! In other words,
    printf made a copy of the pointer returned from func3 with its
    value of ########. The pointer returned from func4 was the
    same so it did not take the new value @@@@@@@@.
    */
}

/*
OUTPUT:

XXXXXXXX 0
YYYYYYYY 1
ZZZZZZZZ 1
######## ########

*/