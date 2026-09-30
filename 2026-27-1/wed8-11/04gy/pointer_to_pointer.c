int main() {
  int k = 8;
  int q = 9;
  int *ptr = &k;

  int **qtr = &ptr;

  *qtr = &q;

  **qtr = 12;
}
