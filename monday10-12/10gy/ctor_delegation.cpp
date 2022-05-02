#include <iostream>

struct Description {
  std::string desc;
  std::string shortDesc;

  Description(std::string _desc, std::string _shortDesc)
    : desc(_desc), shortDesc(_shortDesc) {}

  Description(std::string _desc) : Description(_desc, _desc) {}
};

int main() {
  
}
