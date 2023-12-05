struct A {
  int i, j;

  A(int i) : i(i) {}

  A(int i, int j) : A(i) {}
};
