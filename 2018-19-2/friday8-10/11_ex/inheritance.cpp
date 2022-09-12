#include <iostream>
#include <vector>

struct Sikidom {
  double x, y;

  virtual double terulet() const = 0;
};

struct Kor : public Sikidom {
  double r;
  Kor(double r_) : r(r_) {}

  double terulet() const override {
    return 3.14 * r * r;
  }
};

struct Teglalap : public Sikidom {
  double height, width;
  Teglalap(double h, double w) : height(h), width(w) {}

  double terulet() const override {
    return height * width;
  }
};

void onlyAcceptsKor(Kor *k) {
  // complicated stuff 
  std::cout << "Recieved kor: " << k->terulet() << '\n';
}

int main() {
  Kor k(4);
  Teglalap t(6.1, 5.1);

  std::vector<Sikidom *> v;

  v.push_back(&k);
  v.push_back(&t);

  for (auto it = v.begin(); it != v.end(); ++it) {
    Kor *k = dynamic_cast<Kor *>(*it);
    if (k)
      onlyAcceptsKor(k);
  }
}
