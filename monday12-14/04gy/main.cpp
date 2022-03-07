#include <iostream>
#include <fstream>

char encrypt(char c);

int main() {
  std::ifstream ifs("input.txt");
  if (ifs.fail()) {
    std::cout << "Failed to open 'input.txt'!\n";
    return 1;
  }

  std::string input;

  //std::cout << "Please provide a character encode: ";
  std::getline(ifs, input);

  std::string output;
  for (int i = 0; i < input.size(); ++i) {
    output = output + encrypt(input[i]);
  }

  std::cout << "Your encoded character is: " << output << '\n';
} 

char encrypt(char c) {
  std::string from = {'a', 'e', 'i', 'o', 'u'};
  std::string to   = {'u', 'a', 'e', 'i', 'o'};

  char output = c;

  for (int i = 0; i < sizeof(from) / sizeof(from[0]); ++i) {
    if (c == from[i]) {
      output = to[i];
      break;
    }
  }

  return output;
}
