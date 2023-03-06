#include <iostream>

int main() {
  std::cout << "Kérem adja meg a nevének kezdőbetűjét!\n";

  char c;

  std::cin >> c;

  switch (c) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
      std::cout << "Magánhangzó!";
      break;
    default:
      std::cout << "Mássalhangzó!";
      break;
  }

  // if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
  //   std::cout << "Magánhangzó!";
  // else
  //   std::cout << "Mássalhangzó!";

}
