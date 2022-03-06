
#include <iostream>

double mulByTwo(double p) {
  return 2*p;
}

int main() {
  char input;

  std::cout << "Please provide the character to encode: ";
  std::cin >> input;

  char from[] = {'a', 'e', 'i', 'o', 'u'};
  char to  [] = {'u', 'a', 'e', 'i', 'o'};

  char result;

  for (int i = 0; i < sizeof(from) / sizeof(from[0]); ++i) {
    if (input == from[i]) {
      result = to[i];
      break;
    }
  }

  std::cout << "Your encoded character is: " << result << '\n';
}
