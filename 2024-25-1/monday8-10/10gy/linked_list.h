#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iosfwd>
#include <iterator>

template <class T>
struct Node;

//===-------------------------------------------------===//
// Iterátor: (nem konstansra mutató) pointerek
// általánosítása
//===-------------------------------------------------===//
namespace detail {

template <class T>
class Iterator {
  Node<T> *ptr;

public:
  Iterator(Node<T> *ptr) : ptr(ptr) {}

  typedef std::forward_iterator_tag iterator_category;
  typedef T value_type;
  typedef std::ptrdiff_t difference_type;
  typedef T* pointer;
  typedef T& reference;

  bool operator==(Iterator other) { return ptr == other.ptr; }
  bool operator!=(Iterator other) { return !(*this == other); }
  // ++prefix
  Iterator &operator++();
  // postfix++
  Iterator operator++(int);
  T &operator*();

  template <class>
  friend class ConstIterator;
};
} // namespace detail

//===-------------------------------------------------===//
// Konstans Iterátor: konstansra mutató pointerek
// általánosítása
//===-------------------------------------------------===//
namespace detail {

template <class T>
class ConstIterator {
  const Node<T> *ptr;

public:
  ConstIterator(Node<T> *ptr) : ptr(ptr) {}
  // Konverziós konstruktor
  ConstIterator(Iterator<T> it) : ptr(it.ptr) {}

  typedef std::forward_iterator_tag iterator_category;
  typedef const T value_type;
  typedef std::ptrdiff_t difference_type;
  typedef const T* pointer;
  typedef const T& reference;

  bool operator==(ConstIterator other) { return ptr == other.ptr; }
  bool operator!=(ConstIterator other) { return !(*this == other); }

  // ++prefix
  ConstIterator &operator++();
  // postfix++
  ConstIterator operator++(int);
  const T &operator*();
};
} // namespace detail

//===-------------------------------------------------===//
// Node és List definíciója
//===-------------------------------------------------===//

template <class T>
struct Node {
  T data;
  Node *next;
  Node(const T& data, Node *next) : data(data), next(next) {}
};

template <class T>
class List {
  Node<T> *head = nullptr;
  void free();

public:
  typedef detail::Iterator<T> Iterator;
  using ConstIterator = detail::ConstIterator<T>;

  // (default) konstruktor
  List() = default;
  // destruktor
  ~List() { free(); }
  // copy konstruktor (List l2 = l)
  List(const List &other);
  // értékadó operátor (l2 = l)
  List &operator=(const List &other);

  Iterator begin() { return Iterator{head}; }
  Iterator end() { return Iterator{nullptr}; }

  ConstIterator begin() const { return {head}; }
  ConstIterator end() const { return {nullptr}; }

  void push_back(const T &data);
};

template <class T>
std::ostream &operator<<(std::ostream &out, const List<T> &l);

//===-------------------------------------------------===//
// implementáció
//===-------------------------------------------------===//

#include <iostream>

//===-------------------------------------------------===//
// Iterator implementáció
//===-------------------------------------------------===//

namespace detail {
// ++prefix
template <class T>
Iterator<T> &Iterator<T>::operator++() {
  ptr = ptr->next;
  return *this;
}

// postfix++
template <class T>
Iterator<T> Iterator<T>::operator++(int) {
  Iterator ret = *this;
  ptr = ptr->next;
  return ret;
}

template <class T>
T &Iterator<T>::operator*() { return ptr->data; }
} // namespace detail

//===-------------------------------------------------===//
// ConstIterator implementáció
//===-------------------------------------------------===//

namespace detail {
// ++prefix
template <class T>
ConstIterator<T> &ConstIterator<T>::operator++() {
  ptr = ptr->next;
  return *this;
}

// postfix++
template <class T>
ConstIterator<T> ConstIterator<T>::operator++(int) {
  ConstIterator ret = *this;
  ptr = ptr->next;
  return ret;
}

template <class T>
const T &ConstIterator<T>::operator*() { return ptr->data; }
} // namespace detail

//===-------------------------------------------------===//
// List implementáció
//===-------------------------------------------------===//

template <class T>
void List<T>::free() {
  Node<T> *ptr = head;
  while (ptr) {
    Node<T> *nextPtr = ptr->next;
    delete ptr;
    ptr = nextPtr;
  }
}

// copy konstruktor (List l2 = l)
template <class T>
List<T>::List(const List &other) {
  Node<T> *ptr = other.head;
  while (ptr) {
    push_back(ptr->data);
    ptr = ptr->next;
  }
}

// értékadó operátor (l2 = l)
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
void List<T>::push_back(const T &data) {
  Node<T> **ptr = &head;
  while (*ptr)
    ptr = &(*ptr)->next;
  *ptr = new Node<T>{data, nullptr};
}

template <class T>
std::ostream &operator<<(std::ostream &out, const List<T> &l) {
  for (typename List<T>::ConstIterator it = l.begin(); it != l.end();
       ++it) {
    out << *it << '\n';
  }
  return out;
}
#endif // LINKED_LIST_H
