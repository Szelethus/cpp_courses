#include <iostream>

struct Node {
  const int data;
  Node *next;

  Node(int data, Node *next) : data(data), next(next) {}
};

class List {
  Node *head;

public:
  List() : head(nullptr) {}

  ~List() {
    free();
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

  void display() {
    for (Node *ptr = head; ptr != nullptr; ptr = ptr->next) {
      std::cout << ptr->data << '\n';
    }
  }
};

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
  l.display();
}
