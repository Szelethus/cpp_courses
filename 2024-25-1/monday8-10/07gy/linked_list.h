#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct Node;

//===-------------------------------------------------===//
// Iterátor: (nem konstansra mutató) pointerek
// általánosítása
//===-------------------------------------------------===//
namespace detail {
class Iterator {
  Node *ptr;

public:
  Iterator(Node *ptr) : ptr(ptr) {}

  bool operator==(Iterator other) { return ptr == other.ptr; }
  bool operator!=(Iterator other) { return !(*this == other); }
  // ++prefix
  Iterator &operator++();
  // postfix++
  Iterator operator++(int);
  int &operator*();

  friend class ConstIterator;
};
} // namespace detail

//===-------------------------------------------------===//
// Konstans Iterátor: konstansra mutató pointerek
// általánosítása
//===-------------------------------------------------===//
namespace detail {
class ConstIterator {
  const Node *ptr;

public:
  ConstIterator(Node *ptr) : ptr(ptr) {}
  // Konverziós konstruktor
  ConstIterator(Iterator it) : ptr(it.ptr) {}

  bool operator==(ConstIterator other) { return ptr == other.ptr; }
  bool operator!=(ConstIterator other) { return !(*this == other); }

  // ++prefix
  ConstIterator &operator++();
  // postfix++
  ConstIterator operator++(int);
  // FIXME templates
  int operator*();
};
} // namespace detail

//===-------------------------------------------------===//
// Node és List definíciója
//===-------------------------------------------------===//
struct Node {
  int data;
  Node *next;
};

class List {
  Node *head = nullptr;
  void free();

public:
  typedef detail::Iterator Iterator;
  using ConstIterator = detail::ConstIterator;

  // (default) konstruktor
  List() = default;
  // destruktor
  ~List() { free(); }
  // copy konstruktor (List l2 = l)
  List(const List &other);
  // értékadó operátor (l2 = l)
  List &operator=(const List &other);

  Iterator begin() { return Iterator{head}; }
  Iterator end() { return Iterator{nullptr}; }

  ConstIterator begin() const { return {head}; }
  ConstIterator end() const { return {nullptr}; }

  void push_back(int data);
};

void display(const List &l);

#endif // LINKED_LIST_H
