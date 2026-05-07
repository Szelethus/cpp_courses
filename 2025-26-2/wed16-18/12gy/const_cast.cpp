
int mulByTwo(int *k) {
  return *k * 2;
}

int main() {
  const int k = 10;

  mulByTwo(const_cast<int *>(&k));
}
