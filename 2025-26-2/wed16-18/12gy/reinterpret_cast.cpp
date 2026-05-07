#include <vector>

struct Airplane {
  std::vector<int> &seats;
  int ID;

  Airplane(std::vector<int> &seats, int ID)
    : seats(seats), ID(ID) {}
};

int main() {
  char buffer[sizeof(Airplane)];

  Airplane *air = reinterpret_cast<Airplane*>(&buffer); 

  std::vector<int> seats = {1,2,3,4,5};

  new (air) Airplane(seats, 33);

}
