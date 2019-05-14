#include <iostream>
#include <vector>

struct Sikidom {
  double x, y;

  Sikidom(double x, double y) : x(x), y(y) {}

  void print() const {
    std::cout << x << ' ' << y;
  }

  virtual ~Sikidom() {}

  virtual double terulet() const = 0;

  virtual Sikidom *clone() const = 0;

  void printMiddle() {
    std::cout << "x: " << x << " y: " << y << '\n';
  }
};

struct Kor : public Sikidom {
  double r;

  int *ptr;

  Kor(double x, double y, double r) : Sikidom(x, y), r(r), ptr(new int) {}

  ~Kor() {
    delete ptr;
  }

  double terulet() const override {
    return 3.14 * r * r;
  }

  virtual Sikidom *clone() const override {
    Kor *tmp = new Kor(*this);
    tmp->ptr = new int;
    return tmp;
  }
};

struct Teglalap : public Sikidom {
  double width, height;

  Teglalap(double x, double y, double width, double height) : width(width), Sikidom(x, y), height(height) {}

  double terulet() const override {
    return width * height;
  }

  virtual Sikidom *clone() const override {
    return new Teglalap(*this);
  }
};

int main() {
  std::vector<Sikidom *> v;

  v.push_back(new Kor(3, 2, 4.5));
  v.push_back(new Teglalap(1, 0, 4.2, 5));

  std::vector<Sikidom *> v2;

  for (Sikidom *elem : v) {
    v2.push_back(elem->clone());
  }

  for (Sikidom *elem : v) {
    elem->printMiddle();
  }

  for (auto it = v.begin(); it != v.end(); ++it)
    delete *it;
  for (auto it = v2.begin(); it != v2.end(); ++it)
    delete *it;
}
