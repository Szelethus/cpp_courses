#include <iostream>
#include <fstream>

int main() {
  std::string from = "aeiou";
  std::string to =   "eioua";

  std::ifstream ifs("input.txt");
  std::string data;

  int n;
  ifs >> n;
  ifs.ignore();

  //while (ifs) {
  for (int i = 0; i < n; ++i) {
    std::string tmp;
    std::getline(ifs, tmp);
    data += tmp + '\n';
  }
  
  for (int i = 0; i < data.size(); ++i) {
    for (int j = 0; j < from.size(); ++j) {
      if (data[i] == from[j]) {
        data[i] = to[j];
        break;
      }
    }
  }

  std::cout << data;
}
