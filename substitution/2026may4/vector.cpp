#include <iostream>
#include <cassert>
#include <stdexcept>

template <class T>
class Iterator {
  T *ptr;

public:
  Iterator(T *ptr) : ptr(ptr) {}

  Iterator operator++() {
    ++ptr;
    return *this;
  }

  Iterator operator--() {
    --ptr;
    return *this;
  }

  Iterator operator+(int offset) {
    ptr += offset;
    return *this;
  }

  Iterator operator-(int offset) {
    return operator+(-offset);
  }

  T &operator*() {
    return *ptr;
  }

  bool operator==(Iterator other) {
    return ptr == other.ptr;
  }

  bool operator!=(Iterator other) {
    return !(*this == other);
  }
};

template <class T>
class Vector {
  unsigned size = 0;
  unsigned capacity = 1;
  T *array;
  
public:
  Vector() : array(new T[1]) {}

  ~Vector() {
    delete[] array;
  }

  Iterator<T> begin() {
    return Iterator<T>{array};
  }

  Iterator<T> end() {
    return Iterator<T>{array + size};
  }

  void push_back(const T &elem) {
    if (size == capacity) {
      expand();
    }

    array[size] = elem;
    ++size;
  }

  void expand() {
    capacity *= 2;
    T *newArray = new T[capacity];

    for (unsigned i = 0; i < size; ++i) {
      newArray[i] = array[i];
    }

    delete[] array;
    array = newArray;
  }

  T &operator[](int offset) {
    return array[offset];
  }

  T &at(int offset) {
    if (offset >= size)
      throw std::out_of_range("OOPSIE");
    return array[offset];
  }

  unsigned get_size() const { return size; }
};

int main() {
  try {
    Vector<int> vec;

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    for (int i = 0; i < vec.get_size() + 10000; ++i) {
      std::cout << vec[i] << '\n';
      std::cout << vec.at(i) << '\n';
    }

    //for (int i : vec) {
    //  std::cout << i << '\n';
    //}

    //for (Iterator it = vec.begin(); it != vec.end(); ++it) {
    //  int i = *it;
    //  std::cout << i << '\n';
    //}
  } catch(std::exception &e) {
    std::cout << e.what() << '\n';
  }
}
