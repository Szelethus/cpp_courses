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
  char input;

  std::cout << "Please provide a word (only vowels): ";
  std::cin >> input;

  char output = encryptLetter(input);

  std::cout << "Your encrypted word: " << output << '\n';
}
