#include <iostream>
#include <memory>
#include <vector>

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
  Teglalap(double d1, double d2) {
    x = d1;
    y = d2;
  }

  virtual double terulet() const override {
    return x * y;
  }
};

int main() {
  std::vector<std::unique_ptr<Sikidom>> v;

  v.push_back(std::make_unique<Kor>(5));
  v.push_back(std::make_unique<Teglalap>(10, 9));

  std::cout << v[0]->terulet() << '\n';
  std::cout << v[1]->terulet() << '\n';
}
