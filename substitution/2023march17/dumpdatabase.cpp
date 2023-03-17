#include <iostream>

std::string readName();
bool isAdmin(std::string name);
void dumpDatabase();

int main() {
  std::string name = readName();
  if (!isAdmin(name))
    return 1;
  dumpDatabase();
}

void dumpDatabase() {
  #define TANULO(NEPTUN, NAME, AGE) \
    std::cout << "Neptun: " << NEPTUN \
              << ", név: " << NAME \
              << ", kor: " << AGE << '\n';
  
  #include "paste.def"
}
