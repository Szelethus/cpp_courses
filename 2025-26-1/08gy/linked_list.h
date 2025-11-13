#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

template <class T>
struct Node;

//===----------------------------------------------------------===//
// Iterator
//===----------------------------------------------------------===//

namespace detail {

template <class T>
class Iterator {
  Node<T> *ptr;

public:
  Iterator(Node<T> *_ptr) : ptr(_ptr) {}

  // tagfüggvény forward deklaráció
  T &operator*();
  // ++prefix
  Iterator operator++();
  // postfix++
  Iterator operator++(int);
  bool operator==(Iterator other) { return ptr == other.ptr; }
  bool operator!=(Iterator other) { return !(*this == other); }

  template <class>
  friend class ConstIterator;
};

} // end of namespace detail

//===----------------------------------------------------------===//
// ConstIterator
//===----------------------------------------------------------===//

namespace detail {

template <class T>
class ConstIterator {
  const Node<T> *ptr;

public:
  ConstIterator(const Node<T> *_ptr) : ptr(_ptr) {}
  // Konverziós konstruktor
  ConstIterator(Iterator<T> it) : ptr(it.ptr) {}

  // tagfüggvény forward deklaráció
  const T &operator*();
  // ++prefix
  ConstIterator operator++();
  // postfix++
  ConstIterator operator++(int);
  bool operator==(ConstIterator other) { return ptr == other.ptr; }
  bool operator!=(ConstIterator other) { return !(*this == other); }
};

} // end of namespace detail

//===----------------------------------------------------------===//
// Node
//===----------------------------------------------------------===//

template <class T>
struct Node {
  T data;
  Node *next;
};

//===----------------------------------------------------------===//
// List
//===----------------------------------------------------------===//

template <class T>
class List {
private:
  Node<T> *head = nullptr;

  void free();

public:
  // konstruktor
  List() = default;
  // destruktor
  ~List() { free(); }
  // másoló konstruktor
  List(const List &other);
  // értékadó operátor
  List &operator=(const List &other);

  typedef detail::Iterator<T> Iterator;
  using ConstIterator = detail::ConstIterator<T>;

  Iterator begin() { return Iterator{head}; }
  Iterator end() { return Iterator{nullptr}; }

  ConstIterator begin() const { return ConstIterator{head}; }
  ConstIterator end() const { return ConstIterator{nullptr}; }

  void push_back(const T &data);
  void display() const;
  void display2() const;
};

template <class T>
std::ostream &operator<<(std::ostream &out, const List<T> &l);

//===----------------------------------------------------------===//
// Iterator implementáció
//===----------------------------------------------------------===//

namespace detail {

// tagfüggvény definicio
template <class T>
T &Iterator<T>::operator*() { return ptr->data; }

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

} // end of namespace detail

//===----------------------------------------------------------===//
// ConstIterator implementáció
//===----------------------------------------------------------===//

namespace detail {
// tagfüggvény definicio
template <class T>
const T &ConstIterator<T>::operator*() { return ptr->data; }

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
} // end of namespace detail

//===----------------------------------------------------------===//
// List implementáció
//===----------------------------------------------------------===//

template <class T>
void List<T>::free() {
  Node<T> *ptr = head;
  while (ptr != nullptr) {
    Node<T> *nextPtr = ptr->next;
    delete ptr;
    ptr = nextPtr;
  }
}

// másoló konstruktor
template <class T>
List<T>::List(const List<T> &other) {
  Node<T> *ptr = other.head;
  while (ptr != nullptr) {
    push_back(ptr->data);
    ptr = ptr->next;
  }
}

// értékadó operátor
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
void List<T>::push_back(const T &data) {
  Node<T> **ptr = &head;
  while (*ptr != nullptr)
    ptr = &(*ptr)->next;

  *ptr = new Node<T>{data, nullptr};
}

template <class T>
void List<T>::display() const {
  Node<T> *ptr = head;
  while (ptr != nullptr) {
    std::cout << ptr->data << '\n';
    ptr = ptr->next;
  }
}

template <class T>
void List<T>::display2() const {
  for (ConstIterator it = begin(); it != end(); ++it) {
    std::cout << *it << '\n';
  }
}

template <class T>
std::ostream &operator<<(std::ostream &out, const List<T> &l) {
  for (typename List<T>::ConstIterator it = l.begin(); it != l.end(); ++it)
    out << *it << '\n';
  return out;
}
#endif // LINKED_LIST_H
