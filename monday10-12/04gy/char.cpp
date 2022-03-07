#include <iostream>
#include <fstream>

char encode(char c);

int main() {
  std::string input;

  std::ifstream ifs("input.txt");
  if (ifs.fail()) {
    std::cout << "Opening of file 'input.txt' failed!\n";
    return 1;
  }

  //std::cout << "Please provide a character to encode: ";
  std::getline(ifs, input);

  std::string output;
  for (int i = 0; i < input.size(); ++i) {
    output = output + encode(input[i]);
  }

  std::cout << "Your encoded character is: " << output << '\n';
}

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
