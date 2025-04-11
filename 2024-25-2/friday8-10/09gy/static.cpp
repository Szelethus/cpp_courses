#include <iostream>

struct Alma {
  static int counter;

  Alma() {
    counter++;
  }
};

int Alma::counter = 0;

//static int x;
//
//void stat() {
//  static int i = 0;
//  std::cout << i++ << '\n';
//}

int main() {
  Alma a1;
  Alma a2;
  Alma a3;
  Alma a4;

  std::cout << Alma::counter << '\n';
}
