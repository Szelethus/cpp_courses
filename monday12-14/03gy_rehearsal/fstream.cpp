#include <iostream>
#include <fstream>

char encryptLetter(char c) {
  char from[] = {'a', 'e', 'i', 'o', 'u'};
  char to[] = {'u', 'a', 'e', 'i', 'o'};

  char result;

  for (int i = 0; i < sizeof(from); ++i)
    if (c == from[i])
      result = to[i];

  // mention that this will be initialized due to input verification
  // assert(false)?
  return result;
}

bool isVowel(char c) {
  char vowels[] = {'a', 'e', 'i', 'o', 'u'};

  bool result = false;

  for (int i = 0; i < sizeof(vowels); ++i)
    if (c == vowels[i])
      result = true;

  // mention that this will be initialized due to input verification
  return result;
}

int main() {
  std::string input;
  std::string output;

  // absolute path
  // relative path
  std::ifstream file("input.txt");
  if (!file.is_open()) {
    std::cout << "File \'input.txt\' does not exist!\n";
    return 1;
  }

  file >> input;

  // verify input
  for (int i = 0; i < input.size(); ++i) {
    if (!isVowel(input[i])) {
      std::cout << "Your input has (at least one) non-vowel characters in it!\n"
                << "Character no. " << i << " is " << input[i]
                << " (which is not a vowel)\n";
      return 1;
    }
  }

  // += operator
  for (int i = 0; i < input.size(); ++i)
    output += encryptLetter(input[i]);

  std::cout << "Your encrypted word: " << output << '\n';
}
