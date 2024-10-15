#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct Node;

// Iterátor: (nem konstansra mutató) pointerek
// általánosítása
class Iterator {
  Node *ptr;

public:
  Iterator(Node *ptr) : ptr(ptr) {}

  bool operator==(Iterator other) {
    return ptr == other.ptr;
  }

  bool operator!=(Iterator other) {
    return !(*this == other);
  }

  // ++prefix
  Iterator &operator++();
  // postfix++
  Iterator operator++(int);
  int &operator*();

  friend class ConstIterator;
};

// Konstans Iterátor: konstansra mutató pointerek
// általánosítása
class ConstIterator {
  const Node *ptr;

public:
  ConstIterator(Node *ptr) : ptr(ptr) {}
  ConstIterator(Iterator it) : ptr(it.ptr) {}

  bool operator==(ConstIterator other) {
    return ptr == other.ptr;
  }

  bool operator!=(ConstIterator other) {
    return !(*this == other);
  }

  // ++prefix
  ConstIterator &operator++();
  // postfix++
  ConstIterator operator++(int);
  // FIXME templates
  int operator*();
};

struct Node {
  int data;
  Node *next;
};

class List {
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

  // destruktor
  ~List() { free(); }

  // copy konstruktor (List l2 = l)
  List(const List &other) {
    Node *ptr = other.head;
    while (ptr) {
      push_back(ptr->data);
      ptr = ptr->next;
    }
  }

  // értékadó operátor (l2 = l)
  List &operator=(const List &other) {
    if (this == &other)
      return *this;

    free();
    head = nullptr;

    Node *ptr = other.head;
    while (ptr) {
      push_back(ptr->data);
      ptr = ptr->next;
    }
    return *this;
  }

  Iterator begin() { return Iterator{head}; }
  Iterator end() { return Iterator{nullptr}; }

  ConstIterator begin() const { return {head}; }
  ConstIterator end() const { return {nullptr}; }

  void push_back(int data) {
    Node **ptr = &head;
    while (*ptr)
      ptr = &(*ptr)->next;
    *ptr = new Node{data, nullptr};
  }
};

void display(const List &l);

#endif // LINKED_LIST_H
