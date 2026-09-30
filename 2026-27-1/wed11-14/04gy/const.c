int main() {
  const int k = 5;
  const int l = 3;

  //const int * -> konstansra mutató mutató
  const int *ptr = &k;

  //*ptr = 10;
  ptr = &l;


  int a = 6, b = 7;
  // int *const -> konstans mutató
  int * const qtr = &a;

  *qtr = 15;
  //qtr = &b;
  
  // konstansra mutató konstans mutató
  const int *const ctr = &k;
}
