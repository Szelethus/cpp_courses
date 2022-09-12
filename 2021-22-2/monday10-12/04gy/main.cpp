#include <iostream>

char encode(char c) {
  char from[] = {'a', 'e', 'i', 'o', 'u'};
  char to  [] = {'u', 'a', 'e', 'i', 'o'};

  char output = c;

  for (int i = 0; i < sizeof(from) / sizeof(from[0]); ++i) {
    if (c == from[i]) {
      output = to[i];
      break;
    }
  }

  return output;
}

int main() {
  char input;

  std::cin >> std::noskipws;

  std::cout << "Please provide a character to encode: ";
  std::cin >> input;

  char output = encode(input);

  std::cout << "Your encoded character is: " << output << '\n';
}
