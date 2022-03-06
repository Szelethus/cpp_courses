#include <iostream>
#include <cassert>

char encode(char p);

int main() {
  int inputSize;
  std::cout << "Please provide the number of strings: ";
  std::cin >> inputSize;

  std::string input;

  for (int i = 0; i < inputSize; ++i) {
    std::string currentWord;
    // We know that the 0th index is the first element, but the user may not be
    // a programmer!
    std::cout << "Please provide the " << i + 1 << ". character to encode: ";
    std::cin >> currentWord;

    input += currentWord + ' ';
  }

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
