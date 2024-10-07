#include <string>
#include <iostream>

int main() {
  std::string str = "alma";
  
  for (std::string::iterator it = str.begin();
       it != str.end(); ++it) {
    std::cout << *it << '\n';
  }
}
