#include <iostream>

char encrypt(char c) {
  char from[] = {'a', 'e', 'i', 'o', 'u'};
  char to  [] = {'u', 'a', 'e', 'i', 'o'};

  char output;

  for (int i = 0; i < sizeof(from) / sizeof(from[0]); ++i) {
    if (c == from[i]) {
      output = to[i];
      break;
    }
  }

  return output;
}

bool isVowel(char c) {
  char vowels[] = {'a', 'e', 'i', 'o', 'u'};

  for (int i = 0; i < sizeof(vowels) / sizeof(vowels[0]); ++i) {
    if (c == vowels[i]) {
      return true;
    }
  }

  return false;
}

int main() {
  char input;

  std::cout << "Please provide a character encode: ";
  std::cin >> input;
  if (!isVowel(input)) {
    std::cout << "Non-vowel input!\n";
    return 1;
  }

  char output = encrypt(input);

  std::cout << "Your encoded character is: " << output << '\n';
} 
