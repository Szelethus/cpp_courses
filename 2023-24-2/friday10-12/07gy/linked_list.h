#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

//===---------------------------------===//
// Node
//===---------------------------------===//

struct Node {
  int data;
  Node *next;
};

//===---------------------------------===//
// Iterators
//===---------------------------------===//

class Iterator {
  Node *ptr;

public:
  Iterator(Node *_ptr) : ptr(_ptr) {}

  // Prefix++
  Iterator operator++();
  // Postfix++
  Iterator operator++(int);
  bool operator==(Iterator other) { return ptr == other.ptr; }
  bool operator!=(Iterator other) { return !(*this == other); }
  int &operator*() { return ptr->data; }
  friend class ConstIterator;
};

class ConstIterator {
  const Node *ptr;

public:
  ConstIterator(const Node *_ptr) : ptr(_ptr) {}
  ConstIterator(Iterator it) : ptr(it.ptr) {}

  // Prefix++
  ConstIterator operator++();
  // Postfix++
  ConstIterator operator++(int);
  bool operator==(ConstIterator other) { return ptr == other.ptr; }
  bool operator!=(ConstIterator other) { return !(*this == other); }
  // TODO: What if the return value size is much greater?
  int operator*() { return ptr->data; }
};

//===---------------------------------===//
// List
//===---------------------------------===//

class List {
  Node *head = nullptr;

  void free();

public:
  List() = default;
  List(const List &other);

  List &operator=(const List &other);

  ~List() { free(); }

  Iterator begin() { return Iterator(head); }
  Iterator end() { return Iterator(nullptr); }

  ConstIterator begin() const { return ConstIterator(head); }
  ConstIterator end() const { return ConstIterator(nullptr); }

  void push_back(int data);
};

std::ostream &operator<<(std::ostream &out, const List &l);

#endif // LINKED_LIST_H
