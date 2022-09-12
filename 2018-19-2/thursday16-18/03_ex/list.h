#ifndef __LIST_H__
#define __LIST_H__

struct Node {
  int data;
  Node *next;

  Node(int data_) : data(data_), next(nullptr) {}
};

namespace detail {
class Iterator {
  Node *ptr;

public:
  Iterator(Node *ptr_) : ptr(ptr_) {}
  void operator++() { ptr = ptr->next; }
  bool operator==(const Iterator &other) { return ptr == other.ptr; }
  bool operator!=(const Iterator &other) { return !(*this == other); }
  int &operator*() { return ptr->data; }
};
} // end of namespace detail

class List {
  Node *head;

  void free();
  void copyElementsFromList(const List &other);

public:

  typedef detail::Iterator Iterator;

  List() { head = nullptr; }
  List(int size);
  List(const List &other);
  List &operator=(const List &other);
  ~List() { free(); }

  void print() const;
  void add(int data_);

  Iterator begin() { return Iterator(head); }
  Iterator end() { return Iterator(nullptr); }
};

#endif //__LIST_H__
