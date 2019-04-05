#ifndef __LIST_H__
#define __LIST_H__

#include <iosfwd>

namespace detail {
struct Node {
  int data;
  Node *next;

  Node(int data_) : data(data_), next(NULL) {}
};
} // end of namespace detail

namespace detail {
class Iterator {
  Node *ptr;

public:
  Iterator(Node *ptr_) : ptr(ptr_) {}

  void operator++() { ptr = ptr->next; }
  bool operator==(const Iterator &other) { return ptr == other.ptr; }
  bool operator!=(const Iterator &other) { return !(*this == other); }
  int &operator*() { return ptr->data; }

  friend class ConstIterator;
};
} // end of namespace detail

namespace detail {
class ConstIterator {
  const Node *ptr;

public:
  ConstIterator(const Node *ptr_) : ptr(ptr_) {}
  ConstIterator(Iterator other) : ptr(other.ptr) {}

  void operator++() { ptr = ptr->next; }
  bool operator==(const ConstIterator &other) { return ptr == other.ptr; }
  bool operator!=(const ConstIterator &other) { return !(*this == other); }
  int operator*() { return ptr->data; }
};
} // end of namespace detail

class List {
  typedef detail::Iterator Iterator;
  typedef detail::ConstIterator ConstIterator;
  typedef detail::Node Node;

  Node *head;

  void free();
  void copyElements(const List &other);

public:
  List() : head(NULL) {}
  explicit List(int size);

  List(const List &other) : head(NULL) { copyElements(other); }
  List &operator=(const List &other);
  ~List() { free(); }

  Iterator begin() { return Iterator(head); }
  Iterator end() { return Iterator(NULL); }

  ConstIterator begin() const { return ConstIterator(head); }
  ConstIterator end() const { return ConstIterator(NULL); }

  void add(int newData);
};

std::ostream& operator<<(std::ostream &out, const List &l);

#endif // __LIST_H__
