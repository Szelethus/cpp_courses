#include <climits>
#include <iostream>

int main() {
  std::cout << CHAR_BIT << '\n';

  std::cout << sizeof(char) << '\n';
  
  std::cout << sizeof(short int) << '\n';
  std::cout << sizeof(int) << '\n';
  std::cout << sizeof(long int) << '\n';
  std::cout << sizeof(long long int) << '\n';

  std::cout << sizeof(int *) << '\n';
  std::cout << sizeof(char *) << '\n';
  std::cout << sizeof(std::string *) << '\n';

  std::cout << sizeof(float) << '\n';
  std::cout << sizeof(double) << '\n';
  std::cout << sizeof(long double) << '\n';
}
