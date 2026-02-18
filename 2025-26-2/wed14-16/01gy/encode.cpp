#include <iostream>

int main() {
  std::cout << "Please provide a word: ";

  std::string str;
  std::cin >> str;

  char from[5] = {'a', 'e', 'i', 'o', 'u'};
  char to[5]   = {'e', 'i', 'o', 'u', 'a'};

  for (int j = 0; j < str.size(); ++j) {

    for (int i = 0; i < 5; ++i) {
      if (str[j] == from[i]) {
        str[j] = to[i];
        break;
      }
    }

  }

  std::cout << "Your character: " << str << '\n';
}
