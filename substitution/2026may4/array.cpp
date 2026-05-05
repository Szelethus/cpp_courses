
int main() {
  int *ptr = new int;

  delete ptr;

  int *arrayPtr = new int[5];

  delete[] arrayPtr;
}
