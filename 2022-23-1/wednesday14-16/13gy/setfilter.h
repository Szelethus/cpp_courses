#ifndef SETFILTER_H
#define SETFILTER_H

#include <set>
#include <algorithm>
#include <iostream>

template <class T, class BinPred = std::less<T>>
class set_filtering {
  std::set<T, BinPred> filtered;
  std::set<T, BinPred> &original;

  typedef typename std::set<T, BinPred>::iterator set_iter;

public:
  set_filtering(std::set<T, BinPred> &original) : original(original) {}
  
  ~set_filtering() {
    original.insert(filtered.begin(), filtered.end());
  }

  void printFiltered() {
    for (set_iter it = filtered.begin(); it != filtered.end(); ++it)
      std::cout << *it << '\n';
  }

  void filter(const T &val) {
    set_iter it = original.find(val);
    if (it == original.end())
      return;

    filtered.insert(*it);
    original.erase(it);
  }

  void unfilter(const T &val) {
    set_iter it = filtered.find(val);
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

  template <class Pred>
  void operator+=(Pred pred) {
    set_iter it = find_if(original.begin(), original.end(), pred);
    while (it != original.end()) {
      filter(*it);
      it = find_if(original.begin(), original.end(), pred);
    }
  }

  template <class Pred>
  void operator-=(Pred pred) {
    set_iter it = find_if(filtered.begin(), filtered.end(), pred);
    while (it != filtered.end()) {
      unfilter(*it);
      it = find_if(filtered.begin(), filtered.end(), pred);
    }
  }
};

#endif // SETFILTER_H
