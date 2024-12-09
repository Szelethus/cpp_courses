#ifndef SETFILTER_H
#define SETFILTER_H

#include <set>
#include <algorithm>

template <class Key, class BinaryPred = std::less<Key> >
class set_filtering {
  std::set<Key, BinaryPred> &original;
  std::set<Key, BinaryPred> filtered;

  typedef typename std::set<Key, BinaryPred>::iterator set_iter;

public:
  set_filtering(std::set<Key, BinaryPred> &original) : original(original) {}

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
    set_iter it = std::find_if(original.begin(), original.end(), pred);

    while (it != original.end()) {
      filter(*it);
      it = std::find_if(original.begin(), original.end(), pred);
    }
  }

  template <class UnaryPred>
  void operator-=(UnaryPred pred) {
    set_iter it = std::find_if(filtered.begin(), filtered.end(), pred);

    while (it != filtered.end()) {
      unfilter(*it);
      it = std::find_if(filtered.begin(), filtered.end(), pred);
    }
  }
};

#endif // SETFILTER_H
