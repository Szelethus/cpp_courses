#include <iostream>

char encryptLetter(char c) {
  char from[] = {'a', 'e', 'i', 'o', 'u'};
  char to[] = {'u', 'a', 'e', 'i', 'o'};

  char result;

  for (int i = 0; i < sizeof(from); ++i) {
    if (c == from[i]) {
      result = to[i];
    }
  }

  return result;
}

int main() {
  std::string input;

  std::cout << "Please provide a word (only vowels): ";
  std::cin >> input;

  std::string output;

  for (int i = 0; i < input.size(); ++i)
    output += encryptLetter(input[i]);

  std::cout << "Your encrypted word: " << output << '\n';
}
