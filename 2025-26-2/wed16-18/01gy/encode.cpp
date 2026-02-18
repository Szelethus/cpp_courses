#include <iostream>

int main() {
  std::cout << "Please provide a word: ";

  std::string word;
  std::cin >> word;

  char from[5] = {'a', 'e', 'i', 'o', 'u'};
  char to[5]   = {'e', 'i', 'o', 'u', 'a'};

  for (int j = 0; j < word.size(); ++j) {
    for (int i = 0; i < 5; ++i) {
      if (word[j] == from[i]) {
        word[j] = to[i];
        break;
      }
    }
  }

  std::cout << "Your word: " << word << '\n';
}
