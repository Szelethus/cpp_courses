#include <iostream>
struct Node {
  int data;
  Node *next;
};

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
  void display() {
    Node *ptr = head;
    while (ptr != nullptr) {
      std::cout << ptr->data << '\n';
      ptr = ptr->next;
    }
  }
};

void foo(List &l1, List &l2) {
  l1 = l2;
}

int main() {
  List l;

  l.push_back(1);
  l.push_back(2);
  l.push_back(3);

  List l2 = l;

  foo(l2, l2);

  l2.display();

}
