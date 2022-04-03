#include <cassert>
#include <iostream>

class PosComplex {
  const double orig_re;
  const double orig_im;
  double re;
  double im;

public:
  // C-style struct initialization is fine for Complex, but we need a C++
  // constructor for PosComplex.
  PosComplex(double re_ = 0, double im_ = 0)
      : orig_re(re_), orig_im(im_), re(re_), im(im_) {
    assert(re >= 0 && "Real part is negative!");
    assert(im >= 0 && "Im part is negative!");
  }

  void setRe(double re_) {
    assert(re_ >= 0 && "Can't set real part to negative!");
  }

  void setIm(double im_) {
    assert(im_ >= 0 && "Can't set im part to negative!");
  }

  // Needs const to work on const objects. Don't return with reference --
  // that basically undoes private visibility.
  double getRe() const { return re; }
  double getIm() const { return im; }

  // This is a great operator to implement in-class.
  PosComplex operator~() const { return {re, -im}; }

  // Choosing to implement these as operators is poor design -- is it obvious
  // that these operators would only increment one component?
  PosComplex &operator++() {
    re++;
    return *this;
  }

  PosComplex operator++(int) {
    PosComplex prev = *this;
    re++;
    return prev;
  }
};

// Woudln't it be great to formalize PosComplex and Complex' relationship?
struct Complex {
  double re;
  double im;

  Complex(double re_ = 0, double im_ = 0) : re(re_), im(im_) {}

  // Conversion constructor. Constructor delegation may be overkill.
  Complex(PosComplex c) : Complex(c.getRe(), c.getRe()) {}

  // These operators are best as global friend functions, they allow for
  // conversions on the first parameter.
  friend Complex operator+(Complex left, Complex right);
  friend Complex operator-(Complex left, Complex right);
  friend std::ostream &operator<<(std::ostream &out, PosComplex c);
};

Complex operator+(Complex left, Complex right) {
  return {left.re + right.re, left.im + right.im};
}

Complex operator-(Complex left, Complex right) {
  return {left.re + right.re, left.im - right.im};
}

std::ostream &operator<<(std::ostream &out, Complex c) {
  out << c.re;
  if (c.im > 0) {
    out << '+';
  }
  out << c.im << "i";
  return out;
}

int main() {
  PosComplex pc1{1, 2};
  PosComplex pc2{7, 2};
  Complex c1{1, -2};
  Complex c2{-7, 2};
  std::cout << pc1 + pc2 << '\n';
  std::cout << c2 + pc2 << '\n';
  std::cout << pc2 + c2 << '\n';
}
