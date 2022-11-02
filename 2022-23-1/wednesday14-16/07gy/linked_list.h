#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <iosfwd>

//===-------------------------===//
// Iterator
//===-------------------------===//

struct Node;

namespace list_detail {
// Forward iterator
class Iterator {
  Node *ptr;

public:
  explicit Iterator(Node *_ptr) : ptr(_ptr) {}

  // ++Prefix operátor: ++it;
  // int i = 0;
  // (++i) == 1;
  Iterator operator++();

  bool operator==(Iterator other) { return ptr == other.ptr; }
  bool operator!=(Iterator other) { return !(*this == other); }
  int &operator*();

  friend class ConstIterator;
};
} // end of namespace list_detail

//===-------------------------===//
// ConstIterator
//===-------------------------===//

namespace list_detail {
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
} // end of namespace list_detail

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

  void free();

public:
  static int counter;

  typedef list_detail::Iterator Iterator;
  using ConstIterator = list_detail::ConstIterator;

  List() { ++counter; }
  List(const List &other);
  List &operator=(const List &other);

  ~List() { free(); }

  void push_back(int data);
  int length() const;

  // [begin(),
  Iterator begin() { return Iterator{head}; }
  // end())
  Iterator end() { return Iterator{nullptr}; }

  ConstIterator begin() const { return ConstIterator{head}; }
  ConstIterator end() const { return ConstIterator{nullptr}; }
};

std::ostream &operator<<(std::ostream &out, const List &l);

#endif // __LINKED_LIST_H__
