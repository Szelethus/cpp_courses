#include <iostream>

struct Node {
  int data;
  Node *next;
};

class List {
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
  List() = default;

  List(const List &other) {
    Node *ptr = other.head;
    while (ptr != nullptr) {
      push_back(ptr->data);
      ptr = ptr->next;
    }
  }

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

  ~List() {
    free();
  }

  void push_back(int data) {
    Node **ptr = &head;
    while (*ptr != nullptr) {
      ptr = &(*ptr)->next;
    }
    *ptr = new Node{data, nullptr};
  }

  void display2Impl(Node *first, Node *tail) {
    std::cout << first->data << '\n';
    if (tail == nullptr)
      return;
    display2Impl(tail, tail->next);
  }

  void display2() {
    if (head == nullptr)
      return;
    display2Impl(head, head->next);
  }

  void display() const {
    Node *ptr = head;
    while (ptr != nullptr) {
      std::cout << ptr->data << '\n';
      ptr = ptr->next;
    }
  }
};



int main() {
  List l;

  l.push_back(5);
  l.push_back(6);
  l.push_back(7);

  l.push_back(8);
  {
    List l2 = l;
    l2.display2();
  }

}
