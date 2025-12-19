#ifndef SETFILTER_H
#define SETFILTER_H

#include <set>

template <class T, class Compare = typename std::set<T>::key_compare>
class set_filtering {
  std::set<T, Compare> &original;
  std::set<T, Compare> filtered;

  typedef typename std::set<T, Compare>::iterator set_iter;

public:
  set_filtering(std::set<T, Compare> &c) : original(c) {}

  ~set_filtering() {
    original.insert(filtered.begin(), filtered.end());
  }

  void filter(const T &elem) {
    set_iter it = original.find(elem);
    if (it == original.end())
      return;

    filtered.insert(*it);
    original.erase(it);
  }

  void unfilter(const T &elem) {
    set_iter it = filtered.find(elem);
    if (it == filtered.end())
      return;

    original.insert(*it);
    filtered.erase(it);
  }

  void inverse() {
    original.swap(filtered);
  }

  void operator~() {
    inverse();
  }

  template <class UnaryPred>
  void operator+=(UnaryPred pred) {
    for (set_iter it = original.begin(); it != original.end();) {
      if (pred(*it)) {
        filtered.insert(*it);
        it = original.erase(it);
      } else {
        ++it;
      }
    }
  }

  template <class UnaryPred>
  void operator-=(UnaryPred pred) {
    for (set_iter it = filtered.begin(); it != filtered.end();) {
      if (pred(*it)) {
        original.insert(*it);
        it = filtered.erase(it);
      } else {
        ++it;
      }
    }
  }


};

#endif // SETFILTER_H
