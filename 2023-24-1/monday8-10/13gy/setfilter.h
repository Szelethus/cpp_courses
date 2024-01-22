#ifndef SF_H
#define SF_H

#include <set>

template <class T>
class set_filtering {
  std::set<T> &original;
  std::set<T> filtered;

public:
  set_filtering(std::set<T> &original) : original(original) {}

  ~set_filtering() {
    original.insert(filtered.begin(), filtered.end());
  }

  typedef typename std::set<T>::iterator iterator;

  void filter(const T &elem) {
    iterator it = original.find(elem);
    if (it == original.end())
      return;

    filtered.insert(*it);
    original.erase(it);
  }

  void unfilter(const T &elem) {
    iterator it = filtered.find(elem);
    if (it == filtered.end())
      return;

    original.insert(*it);
    filtered.erase(it);
  }

  void inverse() {
    original.swap(filtered);
  }

  void operator~() { inverse(); }

  template <class Pred>
  void operator+=(Pred pred) {
    for (iterator it = original.begin(); it != original.end();) {
      if (pred(*it)) {
        filtered.insert(*it);
        it = original.erase(it);
      }
      else
        ++it;
    }
  }
  
  
};

#endif // SF_H
