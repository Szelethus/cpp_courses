#include <iostream>
#include <vector>

struct Sikidom {
  double x, y;

  Sikidom() : x(0), y(0) {}

  void print() const {
    std::cout << x << ' ' << y;
  }

  virtual double terulet() const {
    return -1;
  }
};

struct Kor : public Sikidom {
  double r;

  Kor(double r) : r(r) {}

  double terulet() const override {
    return 3.14 * r * r;
  }
};

struct Teglalap : public Sikidom {
  double width, height;

  Teglalap(double width, double height) : width(width), height(height) {}

  double terulet() const override {
    return width * height;
  }
};

void printKor(const Kor *k) {
  k->print();
  std::cout << '\n';
}

int main() {
  std::vector<Sikidom *> v;


  v.push_back(new Kor(4.5));
  v.push_back(new Teglalap(4.2, 5));

  for (auto it = v.begin(); it != v.end(); ++it) {
    const Kor *tmp = dynamic_cast<const Kor *>(*it);
    if (tmp != nullptr) {
      printKor(tmp);
    }
  }


  for (auto it = v.begin(); it != v.end(); ++it)
    delete *it;
}
