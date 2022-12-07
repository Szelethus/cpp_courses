#ifndef AECONT_H
#define AECONT_H

#include <deque>
#include <iostream>

template <class T>
class alternating_endpoint_container {
  std::deque<T> cont;
  bool isEndpointBack;

public:
  alternating_endpoint_container() : isEndpointBack(false) {}

  template <class Iter>
  alternating_endpoint_container(Iter begin, Iter end)
    : isEndpointBack(false) {
  
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

  void insert(const T &val) {
    if (isEndpointBack)
      cont.push_back(val);
    else
      cont.push_front(val);
    isEndpointBack = !isEndpointBack;
  }

  void erase() {
    if (isEndpointBack)
      cont.pop_back();
    else
      cont.pop_front();
    isEndpointBack = !isEndpointBack;
  }

  size_t size() const {
    return cont.size();
  }

  T at(size_t idx) const {
    return cont.at(idx);
  }

  T &operator[](size_t idx) {
    return cont[idx];
  }

  const T &operator[](size_t idx) const {
    return cont[idx];
  }
};

#endif // AECONT_H
