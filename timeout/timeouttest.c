#include "../myc.h"


void timeout_h() {
  printf("Inside timeout_hand ...\n");
  // reset timer
  timeout(2, timeout_h);
}


int main(){

  timeout(6, timeout_h);

  for(int i=1;;i++){
    printf("%d : Inside main function\n",i);
    sleep(1);
  }

return 0;
}
