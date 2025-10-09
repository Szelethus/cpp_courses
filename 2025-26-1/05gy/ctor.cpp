
struct A {
  int x;
  int y;

  //A() : x(0), y(0) {}

  // hibás!!!
  //A(int _y) : y(_y), x(y) {}
  
  A(int _x = 0, int _y = 0) : x(_x), y(_y) {}
};

int main() {
  A a;
}
