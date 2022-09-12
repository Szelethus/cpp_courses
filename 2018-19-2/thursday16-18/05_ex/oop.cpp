#include <iostream>

struct Sikidom {
  double x, y;

  virtual double terulet() const { return -1; }
};

struct Kor : public Sikidom {
  int r;

  Kor (int r_) : r(r_) {}

  virtual double terulet() const override {
    return r * r * 3.14;
  }
};

struct Teglalap : public Sikidom {
  virtual double terulet() const override {
    return x * y;
  }
};

int main() {
  Kor k(6);
  Teglalap t;

  t.x = 9;
  t.y = 10;

  Sikidom *s = &k;

  const Kor k2(6);

  const Sikidom *s2 = &k2;

  std::cout << s2->terulet() << '\n';
}
