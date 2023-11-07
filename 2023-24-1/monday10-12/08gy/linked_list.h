#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

template <class T>
struct Node {
  T data;
  Node *next;

  Node(const T &_data, Node *_next) : data(_data), next(_next) {}
};
//------------------------------------------------------------------

namespace detail {
template <class T>
class ConstIterator;
} // namespace detail

// Iterátorok a mutatók általánositásai
namespace detail {
template <class T>
class Iterator {
  Node<T> *ptr;

public:
  explicit Iterator(Node<T> *ptr) : ptr(ptr) {}
  Iterator operator++();
  Iterator operator++(int);
  T &operator*() { return ptr->data; }
  bool operator==(Iterator other) { return ptr == other.ptr; }
  bool operator!=(Iterator other) { return !(*this == other); }
  // konverziós operátor
  operator ConstIterator<T>();
  // friend class ConstIterator;
};
} // namespace detail

//------------------------------------------------------------------
// Konstans iterátorok a konstansra mutató mutatók általánositásai
namespace detail {
template <class T>
class ConstIterator {
  const Node<T> *ptr;

public:
  explicit ConstIterator(const Node<T> *ptr) : ptr(ptr) {}
  // ConstIterator(Iterator it) : ptr(it.ptr) {}
  ConstIterator operator++();
  ConstIterator operator++(int);
  const T &operator*() { return ptr->data; }
  bool operator==(ConstIterator other) { return ptr == other.ptr; }
  bool operator!=(ConstIterator other) { return !(*this == other); }
};
} // namespace detail

//------------------------------------------------------------------
template <class T>
class List {
  Node<T> *head;

public:
  using Iterator = detail::Iterator<T>;
  using ConstIterator = detail::ConstIterator<T>;

  List() : head(nullptr) {}
  ~List() { free(); }

  Iterator begin() { return Iterator(head); }
  Iterator end() { return Iterator(nullptr); }
  ConstIterator begin() const { return ConstIterator(head); }
  ConstIterator end() const { return ConstIterator(nullptr); }

  List(const List &other);
  List &operator=(const List &other);

private:
  void free();

public:
  void push_back(const T &data);
};

template <class T>
std::ostream &operator<<(std::ostream &out, const List<T> &l);

//------------------------------------------------------------------
namespace detail {
template <class T>
Iterator<T> Iterator<T>::operator++() {
  ptr = ptr->next;
  return *this;
}

template <class T>
Iterator<T> Iterator<T>::operator++(int) {
  Iterator prev = *this;
  ptr = ptr->next;
  return prev;
}
// konverziós operátor
template <class T>
Iterator<T>::operator ConstIterator<T>() { return ConstIterator{ptr}; }
} // namespace detail
//------------------------------------------------------------------

namespace detail {
template <class T>
ConstIterator<T> ConstIterator<T>::operator++() {
  ptr = ptr->next;
  return *this;
}
template <class T>
ConstIterator<T> ConstIterator<T>::operator++(int) {
  ConstIterator prev = *this;
  ptr = ptr->next;
  return prev;
}
} // namespace detail
//------------------------------------------------------------------

template <class T>
List<T>::List(const List &other) : head(nullptr) {
  Node<T> *ptr = other.head;
  while (ptr != nullptr) {
    push_back(ptr->data);
    ptr = ptr->next;
  }
}

template <class T>
List<T> &List<T>::operator=(const List<T> &other) {
  if (this == &other)
    return *this;

  free();
  head = nullptr;

  Node<T> *ptr = other.head;
  while (ptr != nullptr) {
    push_back(ptr->data);
    ptr = ptr->next;
  }
  return *this;
}

template <class T>
void List<T>::free() {
  Node<T> *ptr = head;
  while (ptr != nullptr) {
    Node<T> *nextptr = ptr->next;
    delete ptr;
    ptr = nextptr;
  }
}

template <class T>
void List<T>::push_back(const T &data) {
  Node<T> **ptr = &head;
  while (*ptr != nullptr) {
    ptr = &(*ptr)->next;
  }
  *ptr = new Node<T>{data, nullptr};
}

template <class T>
std::ostream &operator<<(std::ostream &out, const List<T> &l) {
  for (typename List<T>::ConstIterator it = l.begin(); it != l.end(); ++it) {
    std::cout << *it << '\n';
  }
  return out;
}
#endif // LINKED_LIST_H
