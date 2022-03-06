#include <iostream>

char encode(char p);

int main() {
  std::string input;

  // CTRL+D, CTRL+D
  while (std::cin.good()) {
    std::string currentWord;
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
