// (1) Az alábbi osztály nem egy félig reguláris típus.
// Változtassuk azzá!

class A {
  int *ptr;

public:
  A() : ptr(new int{5}) {}

  ~A() {
    delete ptr;
  }

  // (1a)
  A(const A &other) {
    ptr = new int;
    *ptr = *other.ptr;
  }

  // (1b)
  A &operator=(const A &other) {
    if (this == &other)
      return *this;

    *ptr = *other.ptr;
    return *this;
  }
};

// (2) Iterator forward iterátora egy int-eket tároló konténernek.
// Fejezzük be az alábbi függvényt, mely egy feltételes keresés!
// 
// Amennyiben a kívánt feltétellel nem rendelkezik egyik elem sem
// a [begin, end) intervallumban, vagy az intervallum üres, térjünk
// vissza end-del!
//
// Amennyiben ilyen tulajdonságú elem létezik, térjünk vissza a rá
// hivatkozó iterátorral!
//
// Az egyszerűség kedvéért a kívánt feltétel legyen az, hogy az
// adott szám nagyobb-e száznál.

bool isGreaterThan100(int i) { return i > 100; }

Iterator find_if(Iterator begin, Iterator end) {
  if (begin == end)
    return end;
  for (Iterator it = begin; it != end; ++it) {
    if (*it > 100)
      return it;
  }
  return end;
}

// (3) Mikor beszélhetünk a template-ek használatánál 
// 'dependent scope'-ról?
