#include <iostream>

void g() { std::cout << "static2\n"; }
static int x;

namespace { // anonim névtér
int k;
void z();
}
