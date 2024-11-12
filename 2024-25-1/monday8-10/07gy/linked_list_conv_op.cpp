#include <iostream>

struct Node;

// Konstans Iterátor: konstansra mutató pointerek
// általánosítása
class ConstIterator {
  const Node *ptr;

public:
  ConstIterator(Node *ptr) : ptr(ptr) {}
  //ConstIterator(Iterator it) : ptr(it.ptr) {}

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

// Iterátor: (nem konstansra mutató) pointerek
// általánosítása
class Iterator {
  Node *ptr;

public:
  Iterator(Node *ptr) : ptr(ptr) {}

  operator ConstIterator() {
    return ConstIterator{ptr};
  }

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

  //friend class ConstIterator;
};

struct Node {
  int data;
  Node *next;
};

// ++prefix
Iterator &Iterator::operator++() {
  ptr = ptr->next;
  return *this;
}

// postfix++
Iterator Iterator::operator++(int) {
  Iterator ret = *this;
  ptr = ptr->next;
  return ret;
}

int &Iterator::operator*() { return ptr->data; }

// ++prefix
ConstIterator &ConstIterator::operator++() {
  ptr = ptr->next;
  return *this;
}

// postfix++
ConstIterator ConstIterator::operator++(int) {
  ConstIterator ret = *this;
  ptr = ptr->next;
  return ret;
}

int ConstIterator::operator*() { return ptr->data; }

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
  ~List() {
    free();
  }

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

  Iterator begin() {
    return Iterator{head};
  }

  Iterator end() {
    return Iterator{nullptr};
  }

  ConstIterator begin() const {
    return {head};
  }

  ConstIterator end() const {
    return {nullptr};
  }

  void display() const {
    for (ConstIterator it = begin();
         it != end(); ++it) {
      std::cout << *it << '\n';
    }
  }

  void push_back(int data) {
    Node **ptr = &head;
    while (*ptr)
      ptr = &(*ptr)->next;
    *ptr = new Node{data, nullptr};
  }
};


int main() {
  List l;
  l.push_back(5);
  l.push_back(6);
  l.push_back(7);

  const List l2 = l;

  Iterator it = l.begin();

  ConstIterator cit = it;

}
