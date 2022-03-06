#include <iostream>
#include <fstream>

char encode(char c);

int main() {
  std::ifstream ifs("input.txt");
  if (ifs.fail()) {
    std::cout << "Failed to open 'input.txt'!\n";
    return 1;
  }

  int inputSize;
  //std::cout << "Please provide the number of words to encode: ";
  ifs >> inputSize;

  if (ifs.fail()) {
    std::cout << "NaN provided for number of words!\n";
    return 1;
  }

  std::string input;
  //std::cout << "Please provide your words to encode: ";

  for (int i = 0; i < inputSize; ++i) {
    std::string currentWord;
    ifs >> currentWord;
    input += currentWord;
  }

  std::string output;

  for (int i = 0; i < input.size(); ++i) {
    output += encode(input[i]);
  }

  std::cout << "Your encoded word is: " << output << '\n';
}

char encode(char c) {
  const char from[] = {'a', 'e', 'i', 'o', 'u'};
  const char to  [] = {'u', 'a', 'e', 'i', 'o'};

  char output = c;

  for (int i = 0; i < sizeof(from) / sizeof(from[0]); ++i) {
    if (c == from[i]) {
      output = to[i];
      break;
    }
  }

  return output;
}
