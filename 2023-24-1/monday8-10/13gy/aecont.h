#ifndef AECONT_H
#define AECONT_H

#include <deque>

template <class T>
class alternating_endpoint_container {
  bool left;
  std::deque<T> cont;

public:
  alternating_endpoint_container() : left(true) {}

  template <class Iter>
  alternating_endpoint_container(Iter begin, Iter end) : left(true) {
    while (begin != end) {
      insert(*begin);
      ++begin;
    }
  }

  void insert(const T &elem) {
    if (left)
      cont.push_front(elem);
    else
      cont.push_back(elem);

    left = !left;
  }

  void erase() {
    if (left)
      cont.pop_front();
    else
      cont.pop_back();

    left = !left;
  }

  size_t size() const {
    return cont.size();
  }

  T& at(int idx) {
    return cont[idx];
  }

  const T& at(int idx) const {
    return cont[idx];
  }

  T& operator[](int idx) {
    return at(idx);
  }

  const T& operator[](int idx) const {
    return at(idx);
  }

  typedef typename std::deque<T>::iterator iterator;

  iterator begin() { return cont.begin(); }
  iterator end() { return cont.end(); }
};

#endif // AECONT_H
