#include <iostream>
#include <memory>
#include <list>
#include <vector>
//
//template <typename T>
//struct X {
//};
//
//template <typename T>
//struct Y {
//};

template <
  template <class, class> 
  class Container
>
struct ParticleCollider {
  Container<int, std::allocator<int>> cont;
};

int main() {
  //Z<X> z1;
  //Z<Y> z2;

  ParticleCollider<std::list> PC;
}
