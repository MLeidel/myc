#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void timeout(int, void f());
void timeout_h();


/***
* timeout(sec) function starts a timer
* for sec seconds and calls "timeout_hand"
* after sec seconds.
***/
void timeout(int sec, void f()) {  // receive address of print
    signal(SIGALRM, f);
    alarm(sec);
}


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
