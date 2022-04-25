int main() {
  int c;
  int d;
  int *p = &c;
  int **q = &p;
  *q = &d;
}
