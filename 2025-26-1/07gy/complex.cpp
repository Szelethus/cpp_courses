
namespace complex_detail {
struct Complex {
  int re;
  int im;

  Complex(int i, int j) : re(i), im(j) {}
  Complex(int i) : re(i) {}
};

Complex operator+(const Complex &lhs, const Complex &rhs) {
  Complex ret{lhs.re + rhs.re, lhs.im + rhs.im};
  return ret;
}
} //end of nouwrhtioer

int main() {
  complex_detail::Complex c1{2, 3};
  complex_detail::Complex c2{4, -2};

  complex_detail::Complex a = c1 + 5;
  complex_detail::Complex b = 5 + c1;

}
