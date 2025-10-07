int main () {
  int *ptr = new int{5};
  delete ptr;

  int *ptr2 = new int[5];
  delete[] ptr2;
}
