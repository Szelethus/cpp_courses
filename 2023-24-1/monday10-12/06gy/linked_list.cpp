#include <iostream>

struct Node {
  int data;
  Node *next;

  Node(int _data, Node *_next) : data(_data), next(_next) {}
};
//------------------------------------------------------------------
//Iterátorok a mutatók általánositásai
class Iterator {
  Node *ptr;

public:
  explicit Iterator(Node *ptr) : ptr(ptr) {}

  Iterator operator++() {
    ptr = ptr->next;
    return *this;
  }
  Iterator operator++(int) {
    Iterator prev = *this;
    ptr = ptr->next;
    return prev;
  }

  int &operator*() {
    return ptr->data;
  }

  bool operator==(Iterator other) {
    return ptr == other.ptr;
  }

  bool operator!=(Iterator other) {
    return !(*this == other);
  }

  friend class ConstIterator;
};
//------------------------------------------------------------------
//Konstans iterátorok a konstansra mutató mutatók általánositásai
class ConstIterator {
  const Node *ptr;

public:
  explicit ConstIterator(const Node *ptr) : ptr(ptr) {}
  ConstIterator(Iterator it) : ptr(it.ptr) {}

  ConstIterator operator++() {
    ptr = ptr->next;
    return *this;
  }
  ConstIterator operator++(int) {
    ConstIterator prev = *this;
    ptr = ptr->next;
    return prev;
  }

  int operator*() {
    return ptr->data;
  }

  bool operator==(ConstIterator other) {
    return ptr == other.ptr;
  }

  bool operator!=(ConstIterator other) {
    return !(*this == other);
  }
};
//------------------------------------------------------------------
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

  List(const List &other) : head(nullptr) {
    Node *ptr = other.head;
    while (ptr != nullptr) {
      push_back(ptr->data);
      ptr = ptr->next;
    }
  }

  List &operator=(const List &other) {
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

private:
  void free() {
    Node *ptr = head;
    while (ptr != nullptr) {
      Node *nextptr = ptr->next;
      delete ptr;
      ptr = nextptr;
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

  List l2 = l;
  l2 = l;

  foo(l2, l2);

  Iterator it = l.begin();
  ConstIterator cit = it;
  ++it; // második elemre mutat
  *it = 100;
  display(l);
}
