#include <iostream>

template <typename T>
struct Store {
  T t;

  void display();
};

template <typename T>
void Store<T>::display() {
  std::cout << t << '\n';
}

int main() {
  Store<int> t{4};
  t.display();
}
