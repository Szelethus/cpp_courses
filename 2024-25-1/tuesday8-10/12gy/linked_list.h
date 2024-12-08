#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iosfwd>
#include <iterator>

template <class T>
struct Node;

//===-------------------------===//
// Iterator definition
//===-------------------------===//
// (nem konstans) pointerek általánosítása

namespace detail {

template <class T>
class Iterator : public std::iterator<std::forward_iterator_tag, T> {
  Node<T> *ptr;

public:
  explicit Iterator(Node<T> *ptr) : ptr(ptr) {}

  // ++prefix
  Iterator &operator++();
  // postfix++
  Iterator operator++(int);

  bool operator==(Iterator other) { return ptr == other.ptr; }
  bool operator!=(Iterator other) { return !(*this == other); }
  T &operator*();

  template <class>
  friend class ConstIterator;
};
} // end of namespace detail

//===-------------------------===//
// ConstIterator definition
//===-------------------------===//
// konstansra mutató pointerek általánosítása

namespace detail {

template <class T>
class ConstIterator : public std::iterator<std::forward_iterator_tag, const T> {
  const Node<T> *ptr;

public:
  ConstIterator(Node<T> *ptr) : ptr(ptr) {}
  // konverziós konstruktor
  ConstIterator(Iterator<T> it) : ptr(it.ptr) {}

  ConstIterator &operator++();
  ConstIterator operator++(int);

  bool operator==(ConstIterator other) { return ptr == other.ptr; }
  bool operator!=(ConstIterator other) { return !(*this == other); }

  const T &operator*();
};
} // end of namespace detail

//===-------------------------===//
// Node definition
//===-------------------------===//
template <class T>
struct Node {
public:
  T data;
  Node *next;
};

//===-------------------------===//
// List definition
//===-------------------------===//
template <class T>
class List {
private:
  Node<T> *head = nullptr;
  void free();

public:
  // (default) konstruktor
  List() = default;
  // másoló konsktrukor
  List(const List &other);
  // értékadó operátor
  List &operator=(const List &other);
  // destruktor
  ~List() { free(); }

  typedef detail::Iterator<T> Iterator;
  using ConstIterator = detail::ConstIterator<T>;

  Iterator begin() { return Iterator{head}; }
  Iterator end() { return Iterator{nullptr}; }
  ConstIterator begin() const { return {head}; }
  ConstIterator end() const { return {nullptr}; }

  void push_back(const T &data);
};

template <class T>
std::ostream &operator<<(std::ostream &out, const List<T> &l);

//===-------------------------===//
// Iterator implementation
//===-------------------------===//

namespace detail {

template <class T>
Iterator<T> &Iterator<T>::operator++() {
  ptr = ptr->next;
  return *this;
}

template <class T>
Iterator<T> Iterator<T>::operator++(int) {
  Iterator curr = *this;
  ptr = ptr->next;
  return curr;
}

template <class T>
T &Iterator<T>::operator*() { return ptr->data; }

} // end of namespace detail

//===-------------------------===//
// ConstIterator implementation
//===-------------------------===//

namespace detail {

template <class T>
ConstIterator<T> &ConstIterator<T>::operator++() {
  ptr = ptr->next;
  return *this;
}

template <class T>
ConstIterator<T> ConstIterator<T>::operator++(int) {
  ConstIterator curr = *this;
  ptr = ptr->next;
  return curr;
}

template <class T>
const T &ConstIterator<T>::operator*() { return ptr->data; }

} // end of namespace detail

//===-------------------------===//
// List implementation
//===-------------------------===//

template <class T>
void List<T>::free() {
  Node<T> *ptr = head;
  while (ptr) {
    Node<T> *nextPtr = ptr->next;
    delete ptr;
    ptr = nextPtr;
  }
}

template <class T>
List<T>::List(const List &other) {
  Node<T> *ptr = other.head;
  while (ptr) {
    this->push_back(ptr->data);
    ptr = ptr->next;
  }
}

template <class T>
List<T> &List<T>::operator=(const List &other) {
  if (this == &other)
    return *this;
  free();
  head = nullptr;

  Node<T> *ptr = other.head;
  while (ptr) {
    this->push_back(ptr->data);
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
std::ostream &operator<<(std::ostream &out, const List<T> &l) {
  for (typename List<T>::ConstIterator it = l.begin();
       it != l.end(); ++it) {
    out << *it << '\n';
  }

  return out;
}

#endif // LINKED_LIST_H
