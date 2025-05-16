#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

//===--------------------------------------------===//
// Iterator
//===--------------------------------------------===//

struct Node;

namespace detail {
class Iterator {
  Node *ptr;

public:
  explicit Iterator(Node *_ptr) : ptr(_ptr) {}

  // ++prefix
  Iterator operator++();
  // postfix++
  Iterator operator++(int);
  int& operator*();

  bool operator==(Iterator other) { return ptr == other.ptr; }
  bool operator!=(Iterator other) { return !(*this == other); }

  friend class ConstIterator;
};
} // end of namespace detail

//===--------------------------------------------===//
// ConstIterator
//===--------------------------------------------===//

namespace detail {
class ConstIterator {
  const Node *ptr;

public:
  explicit ConstIterator(const Node *_ptr)
    : ptr(_ptr) {}
  ConstIterator(Iterator it) : ptr(it.ptr) {}

  // ++prefix
  ConstIterator operator++();
  // postfix++
  ConstIterator operator++(int);
  // TODO template
  int operator*();

  bool operator==(ConstIterator other) { return ptr == other.ptr; }
  bool operator!=(ConstIterator other) { return !(*this == other); }
};
} // end of namespace detail

//===--------------------------------------------===//
// Node
//===--------------------------------------------===//

struct Node {
  int data;
  Node *next;
};

//===--------------------------------------------===//
// List
//===--------------------------------------------===//

class List {
  Node *head = nullptr;

public:
  using Iterator = detail::Iterator;
  using ConstIterator = detail::ConstIterator;

  // konstruktor
  List() = default;

  // destruktor
  ~List() {
    free();
  }

  // másoló konstruktor
  List(const List &other) {
    Node *ptr = other.head;

    while (ptr != nullptr) {
      push_back(ptr->data);
      ptr = ptr->next;
    }
  }

  // értékadó operátor
  List& operator=(const List &other) {
    if (this == &other)
      return *this;

    free();
    head = nullptr;

    Node *ptr = other.head;

    while (ptr != nullptr) {
      push_back(ptr->data);
      ptr = ptr->next;
    }

    return *this;
  }

  void push_back(int data) {
    Node **ptr = &this->head;

    while (*ptr != nullptr) {
      ptr = &(*ptr)->next;
    }

    *ptr = new Node{data, nullptr};
  }

  Iterator begin() {
    return Iterator{head};
  }

  Iterator end() {
    return Iterator{nullptr};
  }

  ConstIterator begin() const {
    return ConstIterator{head};
  }

  ConstIterator end() const {
    return ConstIterator{nullptr};
  }

private:
  void free() {
    Node *ptr = this->head;

    while (ptr != nullptr) {
      Node *nextPtr = ptr->next;
      delete ptr;
      ptr = nextPtr;
    }
  }

public:
  void display() const {
    Node *ptr = this->head;
    while (ptr != nullptr) {
      std::cout << ptr->data << '\n';
      ptr = ptr->next;
    }
  }
};

#endif // LINKED_LIST_H
