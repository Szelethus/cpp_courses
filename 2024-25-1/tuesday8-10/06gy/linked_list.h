#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

struct Node;

//===-------------------------===//
// Iterator definition
//===-------------------------===//
// (nem konstans) pointerek általánosítása
class Iterator {
  Node *ptr;

public:
  Iterator(Node *ptr) : ptr(ptr) {}

  bool operator==(Iterator other) {
    return ptr == other.ptr;
  }

  // ++prefix
  Iterator &operator++();
  // postfix++
  Iterator operator++(int);

  bool operator!=(Iterator other) {
    return !(*this == other);
  }

  int &operator*();
};

//===-------------------------===//
// ConstIterator definition
//===-------------------------===//
// konstansra mutató pointerek általánosítása
class ConstIterator {
  const Node *ptr;

public:
  ConstIterator(Node *ptr) : ptr(ptr) {}

  bool operator==(ConstIterator other) {
    return ptr == other.ptr;
  }

  ConstIterator &operator++();
  ConstIterator operator++(int);

  bool operator!=(ConstIterator other) {
    return !(*this == other);
  }

  // FIXME: templates
  int operator*();
};

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

  void free() {
    Node *ptr = head;
    while (ptr) {
      Node *nextPtr = ptr->next;
      delete ptr;
      ptr = nextPtr;
    }
  }

public:
  // (default) konstruktor
  List() = default;

  // másoló konsktrukor
  List(const List &other) {
    Node *ptr = other.head;
    while (ptr) {
      this->push_back(ptr->data);
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
    while (ptr) {
      this->push_back(ptr->data);
      ptr = ptr->next;
    }
    return *this;
  }
  
  // destruktor
  ~List() {
    free();
  }

  Iterator begin() {
    return Iterator{head};
  }

  Iterator end() {
    return Iterator{nullptr};
  }

  ConstIterator begin() const {
    return {head};
  }

  ConstIterator end() const {
    return {nullptr};
  }

  void push_back(int data) {
    Node **ptr = &head;
    while (*ptr != nullptr)
      ptr = &(*ptr)->next;
    *ptr = new Node{data, nullptr};
  }

  void display() const;
};

#endif // LINKED_LIST_H
