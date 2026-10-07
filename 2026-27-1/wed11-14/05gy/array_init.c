#include <stdio.h>

void init(/*...*/) {
  
}

int main() {
  int t[5];

  // írjuk meg az init függvényt ami
  // inicializálja a t összes elemét!
  init(/*...*/);

  for (int i = 0;
       i < sizeof(t) / sizeof(t[0]);
       ++i) {
    printf("%d\n", t[i]);
  }
}
