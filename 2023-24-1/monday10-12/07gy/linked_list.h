#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iosfwd>

struct Node {
  int data;
  Node *next;

  Node(int _data, Node *_next) : data(_data), next(_next) {}
};
//------------------------------------------------------------------

class ConstIterator;

// Iterátorok a mutatók általánositásai
class Iterator {
  Node *ptr;

public:
  explicit Iterator(Node *ptr) : ptr(ptr) {}
  Iterator operator++();
  Iterator operator++(int);
  int &operator*() { return ptr->data; }
  bool operator==(Iterator other) { return ptr == other.ptr; }
  bool operator!=(Iterator other) { return !(*this == other); }
  // konverziós operátor
  operator ConstIterator();
  // friend class ConstIterator;
};
//------------------------------------------------------------------
// Konstans iterátorok a konstansra mutató mutatók általánositásai
class ConstIterator {
  const Node *ptr;

public:
  explicit ConstIterator(const Node *ptr) : ptr(ptr) {}
  // ConstIterator(Iterator it) : ptr(it.ptr) {}
  ConstIterator operator++();
  ConstIterator operator++(int);
  int operator*() { return ptr->data; }
  bool operator==(ConstIterator other) { return ptr == other.ptr; }
  bool operator!=(ConstIterator other) { return !(*this == other); }
};

//------------------------------------------------------------------
class List {
  Node *head;

public:
  List() : head(nullptr) {}
  ~List() { free(); }

  Iterator begin() { return Iterator(head); }
  Iterator end() { return Iterator(nullptr); }
  ConstIterator begin() const { return ConstIterator(head); }
  ConstIterator end() const { return ConstIterator(nullptr); }

  List(const List &other);
  List &operator=(const List &other);

private:
  void free();

public:
  void push_back(int data);
};

std::ostream &operator<<(std::ostream &out, const List &l);

#endif // LINKED_LIST_H
