#ifndef __AECONT_H__
#define __AECONT_H__

#include <deque>

template <class T>
class alternating_endpoint_container {
  std::deque<T> cont;
  bool isLeft;

public:
  alternating_endpoint_container() : isLeft(true) {}

  template <class Iterator>
  alternating_endpoint_container(Iterator begin, Iterator end) : isLeft(true) {
    while (begin != end) {
      insert(*begin);
      ++begin;
    }
  }

  typedef typename std::deque<T>::iterator iterator;

  void insert(const T &t) {
    if (isLeft)
      cont.push_front(t);
    else
      cont.push_back(t);
    
    isLeft = !isLeft;
  }

  size_t size() const {
    return cont.size();
  }

  T &at(int index) {
    return cont.at(index);
  }

  const T &at(int index) const {
    return cont.at(index);
  }

  T &operator[](int index) {
    return cont.at(index);
  }

  const T &operator[](int index) const {
    return cont.at(index);
  }

  void erase() {
    if (isLeft)
      cont.pop_front();
    else
      cont.pop_back();
    
    isLeft = !isLeft;
  }

  iterator begin() {
    return cont.begin();
  }

  iterator end() {
    return cont.end();
  }
};

#endif
