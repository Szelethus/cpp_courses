#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

//===---------------------------===//
// Iterator
//===---------------------------===//

#include <iosfwd>

struct Node;

// A nem konstans listák iterátora, egy pointer általánosítása
class Iterator {
  Node *ptr;

public:
  explicit Iterator(Node *_ptr) : ptr(_ptr) {}

  // ++Prefix
  //
  // int i = 0;
  // (++i) == 1;
  Iterator operator++();
  // Postfix++
  //
  // int i = 0;
  // (i++) == 0;
  Iterator operator++(int);

  bool operator==(Iterator other) { return ptr == other.ptr; }
  bool operator!=(Iterator other) { return !(*this == other); }

  int &operator*();

  friend class ConstIterator;
};

//===---------------------------===//
// ConstIterator
//===---------------------------===//

// A konstans listák iterátora, egy konstansra mutató pointer
// általánosítása
class ConstIterator {
  const Node *ptr;

public:
  explicit ConstIterator(Node *_ptr) : ptr(_ptr) {}
  // Konverziós konstruktor
  ConstIterator(Iterator it) : ptr(it.ptr) {}

  // ++Prefix
  //
  // int i = 0;
  // (++i) == 1;
  ConstIterator operator++();

  bool operator==(ConstIterator other) { return ptr == other.ptr; }
  bool operator!=(ConstIterator other) { return !(*this == other); }

  int operator*();
};

//===---------------------------===//
// Node
//===---------------------------===//

struct Node {
  int data;
  Node *next;

  Node(int _data, Node *_next) : data(_data), next(_next) {}
};

//===---------------------------===//
// List
//===---------------------------===//

class List {
  Node *head = nullptr;

  void free() {
    Node *ptr = head;
    while (ptr != nullptr) {
      Node *nextPtr = ptr->next;
      delete ptr;
      ptr = nextPtr;
    }
  }

public:
  List() = default;

  ~List() { free(); }

  List(const List &other) {
    for (Node *ptr = other.head; ptr != nullptr; ptr = ptr->next) {
      push_back(ptr->data);
    }
  }

  List &operator=(const List &other) {
    if (this == &other) {
      return *this;
    }

    free();
    head = nullptr;

    for (Node *ptr = other.head; ptr != nullptr; ptr = ptr->next) {
      push_back(ptr->data);
    }
    return *this;
  }

  void push_back(int data) {
    Node **ptr = &head;
    while (*ptr != nullptr) {
      ptr = &(*ptr)->next;
    }

    *ptr = new Node{data, nullptr};
  }

  int length() const {
    int length = 0;
    for (Node *ptr = head; ptr != nullptr; ptr = ptr->next) {
      length += 1;
    }
    return length;
  }

  // [begin(), ...
  Iterator begin() { return Iterator{head}; }
  // ..., end())
  Iterator end() { return Iterator{nullptr}; }

  ConstIterator begin() const { return ConstIterator{head}; }
  ConstIterator end() const { return ConstIterator{nullptr}; }
};

std::ostream &operator<<(std::ostream &out, const List &l);

#endif // _LINKED_LIST_H_
