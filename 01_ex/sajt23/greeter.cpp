#include <iostream>
#include "greeter.h"

std::ostream &Gout2 = std::cout << "wi7tr\n";

void greeter(std::string Name) {
  std::cout << "Hello " << Name << '\n';
}
