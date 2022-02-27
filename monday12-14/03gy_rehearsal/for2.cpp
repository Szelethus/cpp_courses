#include <iostream>

int main() {
  char input;

  std::cout << "Please provide a word (only vowels): ";
  std::cin >> input;

  char output;

  char from[] = {'a', 'e', 'i', 'o', 'u'};
  char to[] = {'u', 'a', 'e', 'i', 'o'};

  for (int i = 0; i < sizeof(from); ++i) {
    if (input == from[i]) {
      output = to[i];
    }
  }

  std::cout << "Your encrypted word: " << output << '\n';
}
