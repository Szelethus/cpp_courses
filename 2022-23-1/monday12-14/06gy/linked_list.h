#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <iosfwd>

//===-------------------------===//
// Iterator
//===-------------------------===//

struct Node;

// Forward iterator
class Iterator {
  Node *ptr;

public:
  explicit Iterator(Node *_ptr) : ptr(_ptr) {}

  // Prefix++ operátor: ++it;
  // int i = 0;
  // (++i) == 1;
  // TODO postfix
  Iterator operator++();

  bool operator==(Iterator other) { return ptr == other.ptr; }
  bool operator!=(Iterator other) { return !(*this == other); }
  int &operator*();

  friend class ConstIterator;
};

//===-------------------------===//
// ConstIterator
//===-------------------------===//

// Forward iterator
class ConstIterator {
  const Node *ptr;

public:
  explicit ConstIterator(const Node *_ptr) : ptr(_ptr) {}
  ConstIterator(Iterator it) : ptr(it.ptr) {}

  // Prefix++ operátor: ++it;
  // int i = 0;
  // (++i) == 1;
  // TODO postfix
  ConstIterator operator++();

  bool operator==(ConstIterator other) { return ptr == other.ptr; }
  bool operator!=(ConstIterator other) { return !(*this == other); }
  int operator*();
};

//===-------------------------===//
// Node
//===-------------------------===//

struct Node {
  int data;
  Node *next;

  Node(int _data, Node *_next) : data(_data), next(_next) {}
};

//===-------------------------===//
// List
//===-------------------------===//

class List {
private:
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

  List(const List &other) {
    for (Node *ptr = other.head; ptr != nullptr; ptr = ptr->next) {
      push_back(ptr->data);
    }
  }

  List &operator=(const List &other) {
    if (this == &other)
      return *this;

    free();
    head = nullptr;

    for (Node *ptr = other.head; ptr != nullptr; ptr = ptr->next) {
      push_back(ptr->data);
    }
    return *this;
  }

  ~List() { free(); }

  void push_back(int data) {
    Node **ptr = &head;
    while ((*ptr) != nullptr) {
      ptr = &(*ptr)->next;
    }
    *ptr = new Node{data, nullptr};
  }

  // [begin(),
  Iterator begin() { return Iterator{head}; }

  // end())
  Iterator end() { return Iterator{nullptr}; }

  ConstIterator begin() const { return ConstIterator{head}; }
  ConstIterator end() const { return ConstIterator{nullptr}; }

  int length() const {
    int length = 0;
    for (Node *ptr = head; ptr != nullptr; ptr = ptr->next) {
      length++;
    }
    return length;
  }
};

std::ostream &operator<<(std::ostream &out, const List &l);

#endif // __LINKED_LIST_H__
