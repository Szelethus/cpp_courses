#include <iostream>

struct Store {
  int i;

  // 1. Implementáljunk egy olyan, paraméterként egy intet
  // váró konstruktort, mely az i adattagnak értékül
  // adja a paramétert. Használjunk inicializációs listát!

  // 2. Implementáljuk az egyenlőség vizsgáló operátort úgy,
  // hogy két Store objektum i adattagjának egyenlőségét
  // vizsgálja!
  
  // 3. Implementáljuk az egyenlőtlenség operátort úgy, hogy
  // az egyenlőség operátor negáltját adja vissza!
};

int main() {
  Store a(3);
  Store b(5);

  if (a == b)
    std::cout << "a and b is equal\n";
  else
    std::cout << "a and b is not equal\n";

  if (a != b)
    std::cout << "a and b is not equal\n";
  else
    std::cout << "a and b is equal\n";

  // Output:
  // a and b is not equal
  // a and b is not equal
}
