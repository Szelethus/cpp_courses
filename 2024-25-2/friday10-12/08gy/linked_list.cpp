#include <iostream>

//===--------------------------------------------===//
// Iterator
//===--------------------------------------------===//

struct Node;

class Iterator {
  Node *ptr;

public:
  explicit Iterator(Node *_ptr) : ptr(_ptr) {}

  // ++prefix
  Iterator operator++();

  // postfix++
  Iterator operator++(int);

  int& operator*();

  bool operator==(Iterator other) {
    return ptr == other.ptr;
  }

  bool operator!=(Iterator other) {
    return !(*this == other);
  }

  friend class ConstIterator;
};

//===--------------------------------------------===//
// ConstIterator
//===--------------------------------------------===//

struct Node;

class ConstIterator {
  const Node *ptr;

public:
  explicit ConstIterator(const Node *_ptr)
    : ptr(_ptr) {}

  ConstIterator(Iterator it) : ptr(it.ptr) {}

  // ++prefix
  ConstIterator operator++();

  // postfix++
  ConstIterator operator++(int);

  // TODO template
  int operator*();

  bool operator==(ConstIterator other) {
    return ptr == other.ptr;
  }

  bool operator!=(ConstIterator other) {
    return !(*this == other);
  }
};

//===--------------------------------------------===//
// Node
//===--------------------------------------------===//

struct Node {
  int data;
  Node *next;
};

//===--------------------------------------------===//
// Iterator implementation
//===--------------------------------------------===//

Iterator Iterator::operator++() {
  ptr = ptr->next;
  return *this;
}

Iterator Iterator::operator++(int) {
  Iterator prev = *this;
  ptr = ptr->next;
  return prev;
}

int& Iterator::operator*() {
  return ptr->data;
}

//===--------------------------------------------===//
// ConstIterator implementation
//===--------------------------------------------===//

ConstIterator ConstIterator::operator++() {
  ptr = ptr->next;
  return *this;
}

ConstIterator ConstIterator::operator++(int) {
  ConstIterator prev = *this;
  ptr = ptr->next;
  return prev;
}

int ConstIterator::operator*() {
  return ptr->data;
}

//===--------------------------------------------===//
// List
//===--------------------------------------------===//

class List {
  Node *head = nullptr;

public:
  // konstruktor
  List() = default;

  // destruktor
  ~List() {
    free();
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

  void push_back(int data) {
    Node **ptr = &this->head;

    while (*ptr != nullptr) {
      ptr = &(*ptr)->next;
    }

    *ptr = new Node{data, nullptr};
  }

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

private:
  void free() {
    Node *ptr = this->head;

    while (ptr != nullptr) {
      Node *nextPtr = ptr->next;
      delete ptr;
      ptr = nextPtr;
    }
  }

public:
  void display() const {
    Node *ptr = this->head;
    while (ptr != nullptr) {
      std::cout << ptr->data << '\n';
      ptr = ptr->next;
    }
  }
};

void print(const List &l) {
  for (ConstIterator it = l.begin();
       it != l.end(); ++it) {
    std::cout << *it << '\n';
  }
}

int main() {
  List l;
  
  l.push_back(5);
  l.push_back(6);
  l.push_back(7);

  Iterator it = l.begin();
  ConstIterator cit = it;

  const List l2 = l;
  ConstIterator cit2 = l2.begin();
  ++cit2;
  //*it = 10;
  print(l2);

  Iterator it3 = Iterator{nullptr};
}
