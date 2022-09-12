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
  std::string from;
  std::string to;

  std::ifstream fromfs("from.txt");
  std::ifstream tofs("to.txt");

  if (fromfs.fail()) {
    std::cout << "Failed to open 'from.txt'!\n";
    return '-';
  }

  if (tofs.fail()) {
    std::cout << "Failed to open 'to.txt'!\n";
    return '-';
  }

  std::getline(fromfs, from);
  std::getline(tofs, to);

  if (from.size() != to.size()) {
    std::cout << "From and To must have the same length!\n";
    return '-';
  }

  char output = c;

  for (int i = 0; i < from.size(); ++i) {
    if (c == from[i]) {
      output = to[i];
      break;
    }
  }

  return output;
}
