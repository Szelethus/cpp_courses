#include <iostream>
#include <vector>

struct Airplane {
  std::vector<int> seats;
  int ID;
};

int main() {
  Airplane air;
  int *i = reinterpret_cast<int*>(&air); 
}
