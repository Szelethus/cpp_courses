
void print(int *i) {
  // ...
}

int main() {
  const int k = 7;

  print(const_cast<int *>(&k));
}
