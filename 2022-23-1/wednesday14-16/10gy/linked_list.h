#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

//===---------------------------===//
// Iterator
//===---------------------------===//

#include <iosfwd>
#include <iterator>

template <class T>
struct Node;

// A nem konstans listák iterátora, egy pointer általánosítása
template <class T>
class Iterator : public std::iterator<std::forward_iterator_tag, T> {
  Node<T> *ptr;

public:
  explicit Iterator(Node<T> *_ptr) : ptr(_ptr) {}

  // ++Prefix
  //
  // T i = 0;
  // (++i) == 1;
  Iterator operator++();
  // Postfix++
  //
  // T i = 0;
  // (i++) == 0;
  Iterator operator++(int);

  bool operator==(Iterator other) { return ptr == other.ptr; }
  bool operator!=(Iterator other) { return !(*this == other); }

  T &operator*();

  template <class R>
  friend class ConstIterator;
};

//===---------------------------===//
// ConstIterator
//===---------------------------===//

// A konstans listák iterátora, egy konstansra mutató pointer
// általánosítása
template <class T>
class ConstIterator {
  const Node<T> *ptr;

public:
  explicit ConstIterator(Node<T> *_ptr) : ptr(_ptr) {}
  // Konverziós konstruktor
  ConstIterator(Iterator<T> it) : ptr(it.ptr) {}

  // ++Prefix
  //
  // T i = 0;
  // (++i) == 1;
  ConstIterator operator++();

  bool operator==(ConstIterator other) { return ptr == other.ptr; }
  bool operator!=(ConstIterator other) { return !(*this == other); }

  T operator*();
};

//===---------------------------===//
// Node
//===---------------------------===//

template <class T>
struct Node {
  T data;
  Node *next;

  Node(T _data, Node *_next) : data(_data), next(_next) {}
};

//===---------------------------===//
// List
//===---------------------------===//

template <class T>
class List {
  Node<T> *head = nullptr;

  void free() {
    Node<T> *ptr = head;
    while (ptr != nullptr) {
      Node<T> *nextPtr = ptr->next;
      delete ptr;
      ptr = nextPtr;
    }
  }

public:
  List() = default;

  ~List() { free(); }

  List(const List &other) {
    for (Node<T> *ptr = other.head; ptr != nullptr; ptr = ptr->next) {
      push_back(ptr->data);
    }
  }

  List &operator=(const List &other) {
    if (this == &other) {
      return *this;
    }

    free();
    head = nullptr;

    for (Node<T> *ptr = other.head; ptr != nullptr; ptr = ptr->next) {
      push_back(ptr->data);
    }
    return *this;
  }

  void push_back(T data) {
    Node<T> **ptr = &head;
    while (*ptr != nullptr) {
      ptr = &(*ptr)->next;
    }

    *ptr = new Node<T>{data, nullptr};
  }

  T length() const {
    T length = 0;
    for (Node<T> *ptr = head; ptr != nullptr; ptr = ptr->next) {
      length += 1;
    }
    return length;
  }

  using iterator = Iterator<T>;
  using Constiterator = ConstIterator<T>;

  // [begin(), ...
  iterator begin() { return iterator{head}; }
  // ..., end())
  iterator end() { return iterator{nullptr}; }

  Constiterator begin() const { return Constiterator{head}; }
  Constiterator end() const { return Constiterator{nullptr}; }
};

template <class T>
std::ostream &operator<<(std::ostream &out, const List<T> &l);

//------------- Implementation 

template <class T>
std::ostream &operator<<(std::ostream &out, const List<T> &l) {
  for (ConstIterator<T> it = l.begin(); it != l.end(); ++it) {
    out << *it << '\n';
  }
  return out;
}

//===---------------------------===//
// Iterator
//===---------------------------===//

// Iterator and ConstIterator method definitions.
template <class T>
Iterator<T> Iterator<T>::operator++() {
  ptr = ptr->next;
  return *this;
}

template <class T>
Iterator<T> Iterator<T>::operator++(int) {
  Iterator ret = *this;
  ptr = ptr->next;
  return ret;
}
template <class T>
T &Iterator<T>::operator*() { return ptr->data; }

//===---------------------------===//
// ConstIterator
//===---------------------------===//

template <class T>
ConstIterator<T> ConstIterator<T>::operator++() {
  ptr = ptr->next;
  return *this;
}
template <class T>
T ConstIterator<T>::operator*() { return ptr->data; }
#endif // _LINKED_LIST_H_
