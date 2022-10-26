// (1) Mi a feladata a destruktornak?

// (2) Az "Iterator" osztály forward iterátora egy inteket
// tároló konténernek.
// Írjunk egy maximum keresést a [begin, end) intervallumra!
// Ha az intervallum üres, térjünk vissza (-1)-el.

int max(Iterator begin, Iterator end) {
  if (begin == end)
    return -1;

  int max = *(begin++);
  for (; begin != end; ++begin) {
    if (max < *begin)
      max = *begin;
  }
  return max;
}

// (3) Mely kettő paramétere NEM lehet egy templatenek?

// (4) Helyes az alábbi kód? Ha nem, miért nem? Ha igen, mit ír ki?

// Fibonacci(N) = Fibonacci(N-2) + Fibonacci(N-1)
template <int N>
struct Fibonacci {
  const static int value = Fibonacci<N-1>::value + Fibonacci<N-2>::value;
};

int main() {
  std::cout << Fibonacci<4>::value << '\n';
}

// (5) Miért nem kellett a fenti kódban explicit hivatkozni arra,
// hogy a << operátor az std névtérből származik?
