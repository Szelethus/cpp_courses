#ifndef SETFILTER_H
#define SETFILTER_H

#include <set>
#include <algorithm>

template <class T, class BinPred = std::less<T>>
class set_filtering {
  std::set<T, BinPred> &original;
  std::set<T, BinPred> filtered;

  typedef typename std::set<T, BinPred>::iterator set_iter;

public:
  set_filtering(std::set<T, BinPred> &s) : original(s) {}

  ~set_filtering() {
    original.insert(filtered.begin(), filtered.end());
  }

  void filter(const T &val) {
    set_iter it = original.find(val);
    if (it == original.end())
      return;

    filtered.insert(*it);
    original.erase(*it);
  }

  void unfilter(const T &val) {
    set_iter it = filtered.find(val);
    if (it == filtered.end())
      return;

    original.insert(*it);
    filtered.erase(*it);
  }

  void inverse() {
    original.swap(filtered);
  }

  void operator~() {
    inverse();
  }

private:
  template <class Pred>
  set_iter findInOriginal(Pred pred) {
    return std::find_if(original.begin(),
                               original.end(),
                               pred);
  }

public:
  template <class Pred>
  void operator+=(Pred pred) {
    set_iter it = findInOriginal(pred);

    while (it != original.end()) {
      filter(*it);
      it = findInOriginal(pred);
    }
  }

  template <class Pred>
  void operator-=(Pred pred) {
    // Don't repeat code...
    set_iter it = std::find_if(filtered.begin(),
                               filtered.end(),
                               pred);

    while (it != filtered.end()) {
      unfilter(*it);
      it = std::find_if(filtered.begin(), filtered.end(), pred);
    }
  }
};

#endif // SETFILTER_H
