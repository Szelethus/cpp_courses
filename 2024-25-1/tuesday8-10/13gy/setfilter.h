#ifndef SETFILTER_H
#define SETFILTER_H

#include <algorithm>
#include <set>

template <class Key, class Compare = std::less<Key> >
class set_filtering {
  std::set<Key, Compare> &original;
  std::set<Key, Compare> filtered;

  typedef typename std::set<Key, Compare>::iterator set_iter;

public:
  set_filtering(std::set<Key, Compare> &original) : original(original) {}

  ~set_filtering() {
    original.insert(filtered.begin(), filtered.end());
  }

  void filter(const Key &elem) {
    set_iter it = original.find(elem);
    if (it == original.end())
      return;

    filtered.insert(*it);
    original.erase(it);
  }

  void unfilter(const Key &elem) {
    set_iter it = filtered.find(elem);
    if (it == filtered.end())
      return;

    original.insert(*it);
    filtered.erase(it);
  }

  void inverse() {
    std::swap(original, filtered);
  }

  void operator~() {
    inverse();
  }

  template <class UnaryPred>
  void operator+=(UnaryPred pred) {
    set_iter it = find_if(original.begin(), original.end(), pred);

    while (it != original.end()) {
      filter(*it);
      it = find_if(original.begin(), original.end(), pred);
    }
  }

  template <class UnaryPred>
  void operator-=(UnaryPred pred) {
    set_iter it = find_if(filtered.begin(), filtered.end(), pred);

    while (it != filtered.end()) {
      unfilter(*it);
      it = find_if(filtered.begin(), filtered.end(), pred);
    }
  }
};

#endif // SETFILTER_H
