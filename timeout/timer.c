#include<stdio.h>
#include<unistd.h>
#include<signal.h>

/*

using signal inside a user timeout function

*/
void timeout(int);
void timeout_hand();


void timeout_hand(){
  printf("Inside timeout_hand ...\n");
  // reset timer
  timeout(2);
}

/***
* timeout(sec) function starts a timer
* for sec seconds and calls "timeout_hand"
* after sec seconds.
***/
void timeout(int sec) {
  signal(SIGALRM,timeout_hand);
  alarm(sec);
}


int main(){

  timeout(2);

  for(int i=1;;i++){
    printf("%d : Inside main function\n",i);
    sleep(1);
  }

return 0;
}
