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
  std::string from;
  std::ifstream fromfs("from.txt");
  if (fromfs.fail()) {
    std::cout << "Failed to open 'from.txt'\n";
    return 'a';
  }

  fromfs >> from;

  std::string to;
  std::ifstream tofs("to.txt");
  if (tofs.fail()) {
    std::cout << "Failed to open 'to.txt'\n";
    return 'a';
  }

  tofs >> to;

  if (from.size() != to.size()) {
    std::cout << "from.txt and to.txt must have the same number of characters!\n";
  }

  char output = c;

  for (int i = 0; i < sizeof(from) / sizeof(from[0]); ++i) {
    if (c == from[i]) {
      output = to[i];
      break;
    }
  }

  return output;
}
