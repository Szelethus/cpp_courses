#include <iostream>
#include <fstream>

char encode(char p);

int main() {
  std::ifstream fs("input.txt");
  if (fs.fail()) {
    std::cout << "Failed to open 'input.txt'!\n";
    return 1;
  }

  std::string input;

  // Reading whitespace characters into std::strings doesn't really work!
  // Even with std::noskipws!

  while (!fs.fail()) {
    std::string currentWord;
    fs >> currentWord;
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
  char to[] = {'u', 'a', 'e', 'i', 'o'};

  char result = p;

  for (int i = 0; i < sizeof(from) / sizeof(from[0]); ++i) {
    if (p == from[i]) {
      result = to[i];
      break;
    }
  }

  return result;
}
