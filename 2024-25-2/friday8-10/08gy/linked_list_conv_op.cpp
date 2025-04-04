#include <iostream>

// class forward declaration
struct Node;

//===-------------------------------------------===//
// ConstIterator
//===-------------------------------------------===//

class ConstIterator {
  const Node *ptr;

public:
  ConstIterator(const Node *_ptr) : ptr(_ptr) {}

  // konverziós konstruktor
  //ConstIterator(Iterator it) : ptr(it.ptr) {}

  // member function declaration
  ConstIterator operator++();

  ConstIterator operator++(int);

  // TODO: template
  int operator*();

  bool operator==(ConstIterator other) {
    return ptr == other.ptr;
  }

  bool operator!=(ConstIterator other) {
    return !(*this == other);
  }
};

//===-------------------------------------------===//
// Iterator
//===-------------------------------------------===//

class Iterator {
  Node *ptr;

public:
  Iterator(Node *_ptr) : ptr(_ptr) {}

  // member function declaration
  Iterator operator++();

  Iterator operator++(int);

  int& operator*();

  bool operator==(Iterator other) {
    return ptr == other.ptr;
  }

  bool operator!=(Iterator other) {
    return !(*this == other);
  }

  // konverziós operátor
  operator ConstIterator() {
    return ConstIterator{ptr};
  }

  //friend class ConstIterator;
};

//===-------------------------------------------===//
// Node
//===-------------------------------------------===//

struct Node {
  int data;
  Node *next;
};

//===-------------------------------------------===//
// Iterator implementation
//===-------------------------------------------===//

// member function definition
// ++it (++prefix)
Iterator Iterator::operator++() {
  ptr = ptr->next;
  return *this;
}

// it++ (postfix++)
Iterator Iterator::operator++(int) {
  Iterator prev = *this;
  ptr = ptr->next;
  return prev;
}

int& Iterator::operator*() {
  return ptr->data;
}

//===-------------------------------------------===//
// ConstIterator implementation
//===-------------------------------------------===//

// member function definition
// ++it (++prefix)
ConstIterator ConstIterator::operator++() {
  ptr = ptr->next;
  return *this;
}

// it++ (postfix++)
ConstIterator ConstIterator::operator++(int) {
  ConstIterator prev = *this;
  ptr = ptr->next;
  return prev;
}

int ConstIterator::operator*() {
  return ptr->data;
}

//===-------------------------------------------===//
// List
//===-------------------------------------------===//

class List {
  Node *head = nullptr;

public:
  // konstruktor
  List() = default;

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
    Node *ptr = head;

    while (ptr != nullptr) {
      Node *nextPtr = ptr->next;
      delete ptr;
      ptr = nextPtr;
    }
  }

public:
  void display() const {
    Node *ptr = head;
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

  l.push_back(1);
  l.push_back(2);
  l.push_back(3);

  Iterator it = l.begin();
  ConstIterator cit = it;

  const List l3 = l;

  //ConstIterator it = l3.begin();
  //++it;

  ////*it = 5;

  //l3.display();
}
