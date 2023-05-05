#include "../myc.h"


void timeout_h() {
  printf("Inside timeout_hand ...\n");
  timeout(2, timeout_h);  // reset timer
}


int main(){

  timeout(6, timeout_h);  // timeout in 6 seconds

  for(int i=1;;i++){
    printf("%d : Inside main function\n",i);
    sleep(1);
  }

return 0;
}

/* OUTPUT
1 : Inside main function
2 : Inside main function
3 : Inside main function
4 : Inside main function
5 : Inside main function
6 : Inside main function
Inside timeout_hand ...
7 : Inside main function
8 : Inside main function
Inside timeout_hand ...
9 : Inside main function
10 : Inside main function
Inside timeout_hand ...
11 : Inside main function
12 : Inside main function
Inside timeout_hand ...
13 : Inside main function
14 : Inside main function
Inside timeout_hand ...
15 : Inside main function
^C
*/