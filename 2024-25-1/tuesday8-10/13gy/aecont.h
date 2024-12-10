#ifndef AECONT_H
#define AECONT_H

#include <deque>

template <class T>
class alternating_endpoint_container {
  std::deque<T> cont;
  bool isLeft;

public:
  alternating_endpoint_container() : isLeft(true) {}

  template <class Iter>
  alternating_endpoint_container(Iter begin, Iter end)
    : alternating_endpoint_container() {
    for (; begin != end; ++begin)
      insert(*begin);
  }

  typedef typename std::deque<T>::iterator iterator;

  iterator begin() {
    return cont.begin();
  }

  iterator end() {
    return cont.end();
  }

  void insert(const T &elem) {
    if (isLeft)
      cont.push_front(elem);
    else
      cont.push_back(elem);

    isLeft = !isLeft;
  }

  void erase() {
    if (isLeft)
      cont.pop_front();
    else
      cont.pop_back();

    isLeft = !isLeft;
  }

  int size() const {
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
};

#endif // AECONT_H
