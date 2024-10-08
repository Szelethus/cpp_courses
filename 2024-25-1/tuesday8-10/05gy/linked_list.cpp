#include <iostream>

struct Node {
public:
  int data;
  Node *next;
};

class List {
private:
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

  // másoló konsktrukor
  List(const List &other) {
    Node *ptr = other.head;
    while (ptr) {
      this->push_back(ptr->data);
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
    while (ptr) {
      this->push_back(ptr->data);
      ptr = ptr->next;
    }
    return *this;
  }
  
  // destruktor
  ~List() {
    free();
  }

  void display() {
    Node *ptr = head;
    while (ptr) {
      std::cout << ptr->data << '\n';
      ptr = ptr->next;
    }
  }

  void push_back(int data) {
    Node **ptr = &head;
    while (*ptr != nullptr)
      ptr = &(*ptr)->next;
    *ptr = new Node{data, nullptr};
  }
};

void foo(List &l1, List &l2) {
  l1 = l2;
}

int main() {
  List l;
  l.push_back(5);
  l.push_back(6);
  l.push_back(7);
  
  List l2{l};
  foo(l2, l2);

  l2.display();

  if (true)
    return -1;

}
