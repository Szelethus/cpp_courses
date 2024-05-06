#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

//===------------------------------------===//
// Node
//===------------------------------------===//

template <class T>
struct Node {
  T data;
  Node *next;
};

//===------------------------------------===//
// Iterator
//===------------------------------------===//

namespace detail {
template <class T>
class Iterator {
  Node<T> *ptr;

public:
  template <class R>
  friend class ConstIterator;

  Iterator(Node<T> *_ptr) : ptr(_ptr) {}

  // prefix++
  Iterator operator++();
  // postfix++
  Iterator operator++(int);
  bool operator==(Iterator other) { return ptr == other.ptr; }
  bool operator!=(Iterator other) { return !(*this == other); }
  T &operator*() { return ptr->data; }
};
} // end of namespace detail

//===------------------------------------===//
// ConstIterator
//===------------------------------------===//

namespace detail {
template <class T>
class ConstIterator {
  const Node<T> *ptr;

public:
  ConstIterator(const Node<T> *_ptr) : ptr(_ptr) {}
  ConstIterator(Iterator<T> it);

  // prefix++
  ConstIterator operator++();
  // postfix++
  ConstIterator operator++(int);
  bool operator==(ConstIterator other) { return ptr == other.ptr; }
  bool operator!=(ConstIterator other) { return !(*this == other); }
  const T &operator*() { return ptr->data; }
};
} // end of namespace detail

//===------------------------------------===//
// List
//===------------------------------------===//

template <class T>
class List {
  Node<T> *head = nullptr;

  void free();

public:
  List() = default;
  List(const List &other);
  List &operator=(const List &other);

  using Iterator = detail::Iterator<T>;
  using ConstIterator = detail::ConstIterator<T>;

  ~List() { free(); }

  Iterator begin() { return Iterator(head); }
  Iterator end() { return Iterator(nullptr); }
  ConstIterator begin() const { return ConstIterator(head); }
  ConstIterator end() const { return ConstIterator(nullptr); }

  void push_back(T data);
};

template <class T>
std::ostream &operator<<(std::ostream &out, const List<T> &l);

//===------------------------------------===//
// Implementation
//===------------------------------------===//

namespace detail {
template <class T>
ConstIterator<T>::ConstIterator(Iterator<T> it) : ptr(it.ptr) {}

// prefix++
template <class T>
ConstIterator<T> ConstIterator<T>::operator++() {
  ptr = ptr->next;
  return *this;
}

// postfix++
template <class T>
ConstIterator<T> ConstIterator<T>::operator++(int) {
  ConstIterator ret = *this;
  ptr = ptr->next;
  return *this;
}

// prefix++
template <class T>
Iterator<T> Iterator<T>::operator++() {
  ptr = ptr->next;
  return *this;
}

// postfix++
template <class T>
Iterator<T> Iterator<T>::operator++(int) {
  Iterator ret = *this;
  ptr = ptr->next;
  return *this;
}
} // end of namespace detail

template <class T>
std::ostream &operator<<(std::ostream &out, const List<T> &l) {
  for (typename List<T>::ConstIterator it = l.begin();
       it != l.end(); ++it) {
    out << *it << '\n';
  }
  return out;
}

template <class T>
void List<T>::push_back(T data) {
  Node<T> **ptr = &head;

  while (*ptr)
    ptr = &(*ptr)->next;

  *ptr = new Node<T>{data, nullptr};
}

template <class T>
List<T>::List(const List<T> &other) {
  Node<T> *ptr = other.head;
  while (ptr) {
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
  while (ptr) {
    push_back(ptr->data);
    ptr = ptr->next;
  }
  return *this;
}

template <class T>
void List<T>::free() {
  Node<T> *ptr = head;
  while (ptr) {
    Node<T> *nextPtr = ptr->next;
    delete ptr;
    ptr = nextPtr;
  }
}
#endif // LINKED_LIST_H
