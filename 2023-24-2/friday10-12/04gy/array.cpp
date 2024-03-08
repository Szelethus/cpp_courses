#include <iostream>

void pass(int (&t)[5]) {
  
}

int main() {
  int t[6];
  pass(t);
}
