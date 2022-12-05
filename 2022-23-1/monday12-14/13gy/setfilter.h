#ifndef SETFILTER_H
#define SETFILTER_H

#include <set>
#include <algorithm>

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
    original.swap(filtered);
  }

  void operator~() {
    inverse();
  }

private:
  template <class Pred>
  set_iter findInOriginal(const Pred &pred) {
    return std::find_if(original.begin(), original.end(), pred);
  }
  template <class Pred>
  set_iter findNotInOriginal(const Pred &pred) {
    return std::find_if_not(original.begin(), original.end(), pred);
  }
  template <class Pred>
  set_iter findInFiltered(const Pred &pred) {
    return std::find_if(filtered.begin(), filtered.end(), pred);
  }

  void filter(set_iter it) {
    filtered.insert(*it);
    original.erase(it);
  }

  void unfilter(set_iter it) {
    original.insert(*it);
    filtered.erase(it);
  }

public:
  template <class Pred>
  void operator+=(const Pred &pred) {
    set_iter it = findInOriginal(pred);
    while (it != original.end()) {
      filter(it);
      it = findInOriginal(pred);
    }
  }
  //template <class Pred>
  //void operator-=(const Pred &pred) {
  //  set_iter it = findNotInOriginal(pred);
  //  while (it != original.end()) {
  //    filter(it);
  //    it = findNotInOriginal(pred);
  //  }
  //}

  template <class Pred>
  void operator-=(const Pred &pred) {
    set_iter it = findInFiltered(pred);
    while (it != filtered.end()) {
      unfilter(it);
      it = findInFiltered(pred);
    }
  }
};

#endif // SETFILTER_H
