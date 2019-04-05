#include <iostream>
#include "greeter.h"

std::ostream &Gout = std::cout << "Sajt\n";

int x;

void sajt() {
  std::cout << "Sajt!: " << x << "\n";
}

int main() {
  std::string CreatorName = "Umann Kristóf";
  greeter(CreatorName);

  sajt();
  std::cout << "main!: " << x << "\n";
}
