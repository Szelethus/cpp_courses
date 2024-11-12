#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

struct Node;

//===-------------------------===//
// Iterator definition
//===-------------------------===//
// (nem konstans) pointerek általánosítása

namespace detail {
class Iterator {
  Node *ptr;

public:
  Iterator(Node *ptr) : ptr(ptr) {}

  // ++prefix
  Iterator &operator++();
  // postfix++
  Iterator operator++(int);

  bool operator==(Iterator other) { return ptr == other.ptr; }
  bool operator!=(Iterator other) { return !(*this == other); }
  int &operator*();

  friend class ConstIterator;
};
} // end of namespace detail

//===-------------------------===//
// ConstIterator definition
//===-------------------------===//
// konstansra mutató pointerek általánosítása

namespace detail {
class ConstIterator {
  const Node *ptr;

public:
  ConstIterator(Node *ptr) : ptr(ptr) {}
  // konverziós konstruktor
  ConstIterator(Iterator it) : ptr(it.ptr) {}

  ConstIterator &operator++();
  ConstIterator operator++(int);

  bool operator==(ConstIterator other) { return ptr == other.ptr; }
  bool operator!=(ConstIterator other) { return !(*this == other); }

  // FIXME: templates
  int operator*();
};
} // end of namespace detail

//===-------------------------===//
// Node definition
//===-------------------------===//
struct Node {
public:
  int data;
  Node *next;
};

//===-------------------------===//
// List definition
//===-------------------------===//
class List {
private:
  Node *head = nullptr;
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

  typedef detail::Iterator Iterator;
  using ConstIterator = detail::ConstIterator;

  Iterator begin() { return Iterator{head}; }
  Iterator end() { return Iterator{nullptr}; }
  ConstIterator begin() const { return {head}; }
  ConstIterator end() const { return {nullptr}; }

  void push_back(int data);

};

void display(const List &l);

#endif // LINKED_LIST_H
