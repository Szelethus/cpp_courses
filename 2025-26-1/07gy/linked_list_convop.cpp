#include <iostream>

struct Node;

//===----------------------------------------------------------===//
// ConstIterator
//===----------------------------------------------------------===//

class ConstIterator {
  const Node *ptr;

public:
  ConstIterator(const Node *_ptr) : ptr(_ptr) {}

  // Konverziós konstruktor
  //ConstIterator(Iterator it) : ptr(it.ptr) {}

  // tagfüggvény forward deklaráció
  const int &operator*();

  // ++prefix
  ConstIterator operator++();

  // postfix++
  ConstIterator operator++(int);

  bool operator==(ConstIterator other) {
    return ptr == other.ptr;
  }

  bool operator!=(ConstIterator other) {
    return !(*this == other);
  }
};

//===----------------------------------------------------------===//
// Iterator
//===----------------------------------------------------------===//

class Iterator {
  Node *ptr;

public:
  Iterator(Node *_ptr) : ptr(_ptr) {}

  // tagfüggvény forward deklaráció
  int &operator*();

  // ++prefix
  Iterator operator++();

  // postfix++
  Iterator operator++(int);

  bool operator==(Iterator other) {
    return ptr == other.ptr;
  }

  bool operator!=(Iterator other) {
    return !(*this == other);
  }

  // Konverziós operátor
  operator ConstIterator() {
    return ConstIterator{ptr};
  }

  //friend class ConstIterator;
};

//===----------------------------------------------------------===//
// Node
//===----------------------------------------------------------===//

struct Node {
  int data;
  Node *next;
};

//===----------------------------------------------------------===//
// Iterator implementáció
//===----------------------------------------------------------===//

// tagfüggvény definicio
int &Iterator::operator*() {
  return ptr->data;
}

Iterator Iterator::operator++() {
  ptr = ptr->next;
  return *this;
}

Iterator Iterator::operator++(int) {
  Iterator prev = *this;
  ptr = ptr->next;
  return prev;
}

//===----------------------------------------------------------===//
// ConstIterator implementáció
//===----------------------------------------------------------===//

// tagfüggvény definicio
const int &ConstIterator::operator*() {
  return ptr->data;
}

ConstIterator ConstIterator::operator++() {
  ptr = ptr->next;
  return *this;
}

ConstIterator ConstIterator::operator++(int) {
  ConstIterator prev = *this;
  ptr = ptr->next;
  return prev;
}

//===----------------------------------------------------------===//
// List
//===----------------------------------------------------------===//

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

  Iterator begin() {
    Iterator it{head};
    return it;
  }

  Iterator end() {
    return Iterator{nullptr};
  }

  ConstIterator begin() const {
    ConstIterator it{head};
    return it;
  }

  ConstIterator end() const {
    return ConstIterator{nullptr};
  }

  void push_back(int data) {
    Node **ptr = &head;
    while (*ptr != nullptr)
      ptr = &(*ptr)->next;
    
    *ptr = new Node{data, nullptr};
  }

  void display() const {
    Node *ptr = head;
    while (ptr != nullptr) {
      std::cout << ptr->data << '\n';
      ptr = ptr->next;
    }
  }

  void display2() const {
    for (ConstIterator it = begin(); it != end(); ++it) {
      std::cout << *it << '\n';
    }
  }

};

//===----------------------------------------------------------===//
// Egyéb
//===----------------------------------------------------------===//

void foo(List &l1, List &l2) {
  l1 = l2;
}

int main() {
  List l;
  l.push_back(5);
  l.push_back(6);
  l.push_back(7);

  Iterator it = l.begin();

  ConstIterator cit = static_cast<ConstIterator>(it);
}
