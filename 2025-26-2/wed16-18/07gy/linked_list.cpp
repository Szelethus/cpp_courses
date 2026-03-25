#include <algorithm>
#include <iostream>

// osztály deklaráció
struct Node;

//===-------------------------------------===//
// Iterator
//===-------------------------------------===//

// Mutatók (Node *) általánosítása
class Iterator {
  Node *ptr;

public:
  explicit Iterator(Node *ptr) : ptr(ptr) {}

  // ++it;
  Iterator operator++();
  // it++
  Iterator operator++(int);
  int &operator*();

  bool operator==(Iterator other) {
    return ptr == other.ptr;
  }

  bool operator!=(Iterator other) {
    return !(*this == other);
  }

  friend class ConstIterator;
};

//===-------------------------------------===//
// ConstIterator
//===-------------------------------------===//

// Konstansra mutató mutatók (const Node *)
// általánosítása
class ConstIterator {
  const Node *ptr;

public:
  explicit ConstIterator(const Node *ptr) : ptr(ptr) {}
  // konverziós konstruktor
  ConstIterator(Iterator other) : ptr(other.ptr) {}

  // ++it;
  ConstIterator operator++();
  // it++
  ConstIterator operator++(int);
  int operator*();

  bool operator==(ConstIterator other) {
    return ptr == other.ptr;
  }

  bool operator!=(ConstIterator other) {
    return !(*this == other);
  }
};

//===-------------------------------------===//
// Node
//===-------------------------------------===//

struct Node {
  int data;
  Node *next;
};

//===-------------------------------------===//
// Iterator függvények
//===-------------------------------------===//
// ++it;
Iterator Iterator::operator++() {
  ptr = ptr->next;
  return *this;
}

// it++
Iterator Iterator::operator++(int) {
  Iterator pred = *this;
  ptr = ptr->next;
  return pred;
}

int &Iterator::operator*() {
  return ptr->data;
}

//===-------------------------------------===//
// ConstIterator függvények
//===-------------------------------------===//
// ++it;
ConstIterator ConstIterator::operator++() {
  ptr = ptr->next;
  return *this;
}

// it++
ConstIterator ConstIterator::operator++(int) {
  ConstIterator pred = *this;
  ptr = ptr->next;
  return pred;
}

int ConstIterator::operator*() {
  return ptr->data;
}

//===-------------------------------------===//
// List
//===-------------------------------------===//
class List {
  Node *head = nullptr;

public:
  // konstruktor
  List() {}

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

  // destruktor
  ~List() {
    free();
  }

  void push_back(int data) {
    Node **ptr = &head;
  
    while (*ptr != nullptr)
      ptr = &(*ptr)->next;
  
    *ptr = new Node{data, nullptr};
  }

  void print() const {
    Node *ptr = head;
    while (ptr != nullptr) {
      std::cout << ptr->data << '\n';
      ptr = ptr->next;
    }
  }

  void print2() {
    for (Iterator it = begin(); it != end(); ++it) {
      std::cout << *it << '\n';
    }
  }

private:
  void free() {
    Node *ptr = head;
    while (ptr != nullptr) {
      Node *nextPtr = ptr->next;
      delete ptr;
      ptr = nextPtr;
    }
  }
};

//===-------------------------------------===//
// main()
//===-------------------------------------===//

int main() {
  List l;

  l.push_back(5);
  l.push_back(6);
  l.push_back(7);

  const List l2 = l;

  Iterator it1 = l.begin();
  ConstIterator it2 = it1;
  ++it2;
  //*it = 10;

  l2.print();
}
