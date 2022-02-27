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

bool isVowel(char c) {
  char vowels[] = {'a', 'e', 'i', 'o', 'u'};

  bool result = false;
  for (int i = 0; i < sizeof(vowels); ++i)
    if (c == vowels[i])
      result = true;

  return result;
}

int main() {
  std::string input;

  std::cout << "Please provide a word (only vowels): ";
  std::cin >> input;

  for (int i = 0; i < input.size(); ++i) {
    if (!isVowel(input[i])) {
      std::cout << "Input word has a non-vowel character in it!\n";
      return 1;
    }
  }

  std::string output;

  for (int i = 0; i < input.size(); ++i)
    output += encryptLetter(input[i]);

  std::cout << "Your encrypted word: " << output << '\n';
}
