#include <iostream>

// class forward declaration
struct Node;

//===----------------------------------------===//
// Iterator
//===----------------------------------------===//

// Mutató (Node *) általánosítása 
class Iterator {
  Node *ptr;

public:
  Iterator(Node *ptr) : ptr(ptr) {}

  //prefix++
  Iterator operator++();
  //++postfix
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

//===----------------------------------------===//
// ConstIterator
//===----------------------------------------===//

// Konstansra mutató mutató (const Node *)
// általánosítása 
class ConstIterator {
  const Node *ptr;

public:
  ConstIterator(const Node *ptr) : ptr(ptr) {}
  // konverziós konstruktor
  ConstIterator(Iterator it) : ptr(it.ptr) {}

  //prefix++
  ConstIterator operator++();
  //++postfix
  ConstIterator operator++(int);
  int operator*();

  bool operator==(ConstIterator other) {
    return ptr == other.ptr;
  }

  bool operator!=(ConstIterator other) {
    return !(*this == other);
  }
};

//===----------------------------------------===//
// Node
//===----------------------------------------===//
struct Node {
  int data;
  Node *next;
};

//===----------------------------------------===//
// Iterator implementation
//===----------------------------------------===//
//prefix++
Iterator Iterator::operator++() {
  ptr = ptr->next;
  return *this;
}

//++postfix
Iterator Iterator::operator++(int) {
  Iterator ret = *this;
  ptr = ptr->next;
  return ret;
}

int &Iterator::operator*() {
  return ptr->data;
}

//===----------------------------------------===//
// ConstIterator implementation
//===----------------------------------------===//
//prefix++
ConstIterator ConstIterator::operator++() {
  ptr = ptr->next;
  return *this;
}

//++postfix
ConstIterator ConstIterator::operator++(int) {
  ConstIterator ret = *this;
  ptr = ptr->next;
  return ret;
}

int ConstIterator::operator*() {
  return ptr->data;
}

//===----------------------------------------===//
// List
//===----------------------------------------===//
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

  // konstans tagfüggvény
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
}; // end of class List

//===----------------------------------------===//
// main()
//===----------------------------------------===//

void foo(List &l1, List &l2) {
  l1 = l2;
}

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
