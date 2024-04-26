#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

//===------------------------------------===//
// Node
//===------------------------------------===//

struct Node {
  int data;
  Node *next;
};

//===------------------------------------===//
// ConstIterator
//===------------------------------------===//

class Iterator;

class ConstIterator {
  const Node *ptr;

public:
  ConstIterator(const Node *_ptr) : ptr(_ptr) {}
  ConstIterator(Iterator it);

  // prefix++
  ConstIterator operator++();
  // postfix++
  ConstIterator operator++(int);
  bool operator==(ConstIterator other) { return ptr == other.ptr; }
  bool operator!=(ConstIterator other) { return !(*this == other); }
  // TODO: mi van ha ez egyszer nagyobb lesz?
  int operator*() { return ptr->data; }
};

//===------------------------------------===//
// Iterator
//===------------------------------------===//

class Iterator {
  Node *ptr;

public:
  friend class ConstIterator;
  Iterator(Node *_ptr) : ptr(_ptr) {}

  // prefix++
  Iterator operator++();
  // postfix++
  Iterator operator++(int);
  bool operator==(Iterator other) { return ptr == other.ptr; }
  bool operator!=(Iterator other) { return !(*this == other); }
  int &operator*() { return ptr->data; }
};

//===------------------------------------===//
// List
//===------------------------------------===//

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
