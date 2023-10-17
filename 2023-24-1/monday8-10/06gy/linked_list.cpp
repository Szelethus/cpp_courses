#include <iostream>

struct Node {
  int data;
  Node *next;

  Node(int data, Node *next) : data(data), next(next) {}
};
// ---------------------------------------------------
// Mutató általánositása
class Iterator {
  Node *ptr;

public:
  explicit Iterator(Node *ptr) : ptr(ptr) {}

  // prefix operátor
  Iterator operator++() {
    ptr = ptr->next;
    return *this;
  }

  // postfix opearátor
  Iterator operator++(int) {
    Iterator prev = *this;
    ptr = ptr->next;
    return prev;
  }

  int &operator*() {
    return ptr->data;
  }

  bool operator!=(Iterator other) {
    return ptr != other.ptr;
  }

  bool operator==(Iterator other) {
    return !(*this != other);
  }

  friend class ConstIterator;
};
// ---------------------------------------------------
// Konstansra mutató mutató általánositása
class ConstIterator {
  const Node *ptr;

public:
  explicit ConstIterator(const Node *ptr) : ptr(ptr) {}
  ConstIterator(Iterator it) : ptr(it.ptr) {}

  // prefix operátor
  ConstIterator operator++() {
    ptr = ptr->next;
    return *this;
  }

  // postfix opearátor
  ConstIterator operator++(int) {
    ConstIterator prev = *this;
    ptr = ptr->next;
    return prev;
  }

  int operator*() {
    return ptr->data;
  }

  bool operator!=(ConstIterator other) {
    return ptr != other.ptr;
  }

  bool operator==(ConstIterator other) {
    return !(*this != other);
  }
};
// ---------------------------------------------------
class List {
  Node *head;

public:
  List() : head(nullptr) {}

  ~List() {
    free();
  }

  Iterator begin() {
    return Iterator(head);
  }

  Iterator end() {
    return Iterator(nullptr);
  }

  ConstIterator begin() const {
    return ConstIterator(head);
  }

  ConstIterator end() const {
    return ConstIterator(nullptr);
  }

  List(const List &other) {
    Node *ptr = other.head;
    while (ptr != nullptr) {
      push_back(ptr->data);
      ptr = ptr->next;
    }
  }

  List &operator=(const List &other) {
    if (&other == this)
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
  void push_back(int data) {
    Node **ptr = &head;
    while (*ptr != nullptr) {
      ptr = &(*ptr)->next;
    }
    *ptr = new Node{data, nullptr};
  }
};

void display(const List &l) {
  for (ConstIterator it = l.begin(); it != l.end(); ++it) {
    std::cout << *it << '\n';
  }
}

void foo(List &l1, List &l2) {
  l1 = l2;
}

int main() {
  List l{};
  l.push_back(5);
  l.push_back(6);
  l.push_back(7);

  List l2(l);
  l2 = l;

  l = l;
  display(l);

  Iterator it = l.begin();
  // explicit ctor miatt nem lehet
  // it = nullptr;
  ConstIterator cit = it;
  ++it;
  *it = 100;
  std::cout << *it << '\n';

}
