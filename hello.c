#include "hal.h"

#include <stdio.h>
#include <string.h>



static void yazdir(const char *s) {
  hal_send_str(s);
}

static void intyazdir(const char *s, const int a) {
  char out[32];
  snprintf(out,32,s,a);
  hal_send_str(out);
}

int fac(int n){
  int f=1;
  while(n>1){
    f=f*n;
    n--;
  }
  return f;
}

int main(void) {
  hal_setup(CLOCK_FAST);

  // marker for automated benchmarks
  yazdir("Hello World!!!");
  intyazdir("%d\n",fac(5));
  yazdir("#");

  while (1);

  return 0;
}
