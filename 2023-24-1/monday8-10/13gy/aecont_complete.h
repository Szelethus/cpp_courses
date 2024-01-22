#ifndef AECONT_H
#define AECONT_H

#include <deque>

template <class T>
class alternating_endpoint_container {
  bool right = false;
  std::deque<T> cont;

public:
  template <class Iter>
  alternating_endpoint_container(Iter begin, Iter end) {
    while (begin != end) {
      insert(*begin);
      ++begin;
    }
  }

  alternating_endpoint_container() = default;

  void insert(T elem) {
    if (right)
      cont.push_back(elem);
    else
      cont.push_front(elem);
    right = !right;
  }

  size_t size() const {
    return cont.size();
  }

  T &at(int idx) {
    return cont[idx];
  }

  const T &at(int idx) const {
    return cont[idx];
  }

  T &operator[](int idx) {
    return cont[idx];
  }

  const T &operator[](int idx) const {
    return cont[idx];
  }

  void erase() {
    if (right)
      cont.pop_back();
    else
      cont.pop_front();
    right = !right;
  }

  using iterator = typename std::deque<T>::iterator;

  iterator begin() { return cont.begin();}
  iterator end() { return cont.end();}
};


#endif // AECONT_H
