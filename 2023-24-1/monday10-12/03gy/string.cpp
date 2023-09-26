#include <iostream>

int main() {
  std::cout << sizeof("Hello") << '\n';

  char *c = "Hello";
  std::cout << c << '\n';

  std::string str = "Hello";

  std::cout << str.size() << '\n';
  // Visszaadja az std::string (!!) méretét, NEM A tárolt
  // string hosszát!!!
  std::cout << sizeof(str) << '\n';
}
