#include <cstdint>
#include <string>

enum class MyEnum {
  a,
  b,
  c
};

struct A{};

void foo(A *a) {}

int main() {
  int i = static_cast<int>(MyEnum::a);

  //A str = static_cast<A>(MyEnum::c);
  
  int *ptr = static_cast<int *>(malloc(sizeof(int)));

  int j = (int)MyEnum::b;

  const A a;
  foo(const_cast<A *>(&a));


  int *ptr2 = &j;
  intptr_t iptr = reinterpret_cast<intptr_t>(ptr2);
}
