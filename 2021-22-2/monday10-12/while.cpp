#include <iostream>

double mulByTwo(double p) {
  return 2*p;
}

int main() {
  char input;

  std::cout << "Provide a character to encode: ";
  std::cin >> input;

  char from[] = {'a', 'e', 'i', 'o', 'u'};
  char to  [] = {'u', 'a', 'e', 'i', 'o'};

  char output;

  
  for (int i = 0; i < sizeof(from) / sizeof(from[0]); ++i) {
    if (input == from[i]) {
      output = to[i];
      break;
    }
  }

  decltype(mulByTwo(6.6)) d = mulByTwo(6.6);

  std::cout << "Your encoded character: " << output << '\n';
}
