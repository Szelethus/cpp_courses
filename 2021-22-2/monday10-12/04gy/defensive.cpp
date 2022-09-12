#include <iostream>

char encode(char c) {
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
  char vowel[] = {'a', 'e', 'i', 'o', 'u'};
  
  for (int i = 0; i < sizeof(vowel) / sizeof(vowel[0]); ++i) {
    if (c == vowel[i]) {
      return true;
    }
  }
  return false;
}

int main() {
  char input;

  std::cout << "Please provide a character to encode: ";
  std::cin >> input;
  if (!isVowel(input)) {
    std::cout << "Non-vowel provided!\n";
    return 1;
  }

  char output = encode(input);

  std::cout << "Your encoded character is: " << output << '\n';
}
