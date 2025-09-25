void f(int) {
  //std::cout << "int\n";
}
void f(const char *) {
  //std::cout << "char*\n";
}

int main() {
  f(5);
  f("alma");
}
