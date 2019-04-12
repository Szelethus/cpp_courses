#include <iostream>

template <class T>
struct Store {
  T *ptr;

  Store() : ptr(new T) {
    std::cout << "General Store!\n";
  }

  ~Store() {
    delete ptr;
  }

  Store(const Store &other) {
    ptr = new T(*other.ptr);
  }

  Store &operator=(const Store &other) {
    if (this == &other)
      return *this;
    
    delete ptr;

    ptr->foooo();

    ptr = new T(*other.ptr);
    return *this;
  }

  bool operator==(const Store &other) {
    return *ptr == *other.ptr;
  }
};

template<>
struct Store<int> {
  Store() { std::cout << "Special Store!\n"; }

};

int main() {
  Store<int> a, a2;
  Store<double> b;

  a = a2;
}
