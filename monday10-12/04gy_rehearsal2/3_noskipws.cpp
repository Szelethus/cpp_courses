#include <ios>
#include <iostream>

char encode(char p) {
  char from[] = {'a', 'e', 'i', 'o', 'u'};
  char to  [] = {'u', 'a', 'e', 'i', 'o'};

  char result = p;

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
  char input2;

  std::cin >> std::noskipws;

  std::cout << "Please provide two characters to encode: ";
  std::cin >> input >> input2;

  // Comes in handy that we can >reuse< code here!
  char result = encode(input);
  char result2 = encode(input2);

  std::cout << "Your encoded characters are: " << result << ' '
            << result2 << '\n';
}
