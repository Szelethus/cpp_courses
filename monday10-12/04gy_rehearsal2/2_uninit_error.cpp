#include <iostream>

char encode(char p) {
  char from[] = {'a', 'e', 'i', 'o', 'u'};
  char to  [] = {'u', 'a', 'e', 'i', 'o'};

  // For non-vowels, the program is ill-defined.
  // Either check the input, or define how the program should behave on
  // non-vowels.
  // Demonstrate valgrind and memory sanitizer.
  char result;

  for (int i = 0; i < sizeof(from) / sizeof(from[0]); ++i) {
    if (p == from[i]) {
      result = to[i];
      break;
    }
  }
  
  return result;
}

int main() {
  char input;

  std::cout << "Please provide the character to encode: ";
  std::cin >> input;

  // Despire the argument being 'input' and the parameter being 'p',
  // their values will be the same!
  char result = encode(input);

  std::cout << "Your encoded character is: " << result << '\n';
}
