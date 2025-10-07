#include <iostream>
#include <fstream>

char encode(char c) {
  char encoded;
  switch (c) {
  case 'a':
    encoded = 'e';
    break;
  case 'e':
    encoded = 'i';
    break;
  case 'i':
    encoded = 'o';
    break;
  case 'o':
    encoded = 'u';
    break;
  case 'u':
    encoded = 'a';
    break;
  default:
    encoded = c;
  }
  return encoded;
}

int main() {
  std::ifstream ifs("input.txt");
  if (ifs.fail()) {
    std::cout << "Failed to open file!\n";
    return -1;
  }
  std::string str;

  std::string tmp;
  ifs >> tmp;
  while (!ifs.fail()) {
    str += tmp + ' ';
    ifs >> tmp;
  }

  for (int i = 0; i < str.size(); ++i) {
    str[i] = encode(str[i]);
  }

  std::cout << "Your encoded string is: " << str << '\n';
}
