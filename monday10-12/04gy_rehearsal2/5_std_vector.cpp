#include <iostream>

// Declare as many times as you want, but respect ODR
char encode(char p);

int main() {
  std::string input;

  std::cout << "Please provide the character to encode: ";
  std::cin >> input;

  std::string output;

  for (int i = 0; i < input.size(); ++i) {
    output = output + encode(input[i]);
  }

  std::cout << "Your encoded character is: " << output << '\n';
}

char encode(char p) {
  char from[] = {'a', 'e', 'i', 'o', 'u'};
  char to  [] = {'u', 'a', 'e', 'i', 'o'};

  char result = p;

  for (int i = 0; i < sizeof(from) / sizeof(from[0]); ++i) {
    if (p == from[i]) {
      result = to[i];
      break;
    }
  }
  
  return result;
}
