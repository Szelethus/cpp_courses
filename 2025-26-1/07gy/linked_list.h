#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iosfwd>

struct Node;

//===----------------------------------------------------------===//
// Iterator
//===----------------------------------------------------------===//

namespace detail {

class Iterator {
  Node *ptr;

public:
  Iterator(Node *_ptr) : ptr(_ptr) {}

  // tagfüggvény forward deklaráció
  int &operator*();
  // ++prefix
  Iterator operator++();
  // postfix++
  Iterator operator++(int);
  bool operator==(Iterator other) { return ptr == other.ptr; }
  bool operator!=(Iterator other) { return !(*this == other); }
  friend class ConstIterator;
};

} // end of namespace detail

//===----------------------------------------------------------===//
// ConstIterator
//===----------------------------------------------------------===//

namespace detail {

class ConstIterator {
  const Node *ptr;

public:
  ConstIterator(const Node *_ptr) : ptr(_ptr) {}
  // Konverziós konstruktor
  ConstIterator(Iterator it) : ptr(it.ptr) {}

  // tagfüggvény forward deklaráció
  const int &operator*();
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

struct Node {
  int data;
  Node *next;
};

//===----------------------------------------------------------===//
// List
//===----------------------------------------------------------===//

class List {
private:
  Node *head = nullptr;

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

  typedef detail::Iterator Iterator;
  using ConstIterator = detail::ConstIterator;

  Iterator begin() { return Iterator{head}; }
  Iterator end() { return Iterator{nullptr}; }

  ConstIterator begin() const { return ConstIterator{head}; }
  ConstIterator end() const { return ConstIterator{nullptr}; }

  void push_back(int data);
  void display() const;
  void display2() const;
};

std::ostream &operator<<(std::ostream &out, const List &l);

#endif // LINKED_LIST_H
