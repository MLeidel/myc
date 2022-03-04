#include <myc.h>


int main (int argc, char *argv[]) {

  char *w1 = malloc(1000);
  char *w2 = malloc(2000);

  multifree(2, w1, w2);

  return 0;

}
