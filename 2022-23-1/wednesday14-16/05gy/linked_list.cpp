#include <iostream>

struct Node {
  int data;
  Node *next;

  Node(int _data, Node *_next) : data(_data), next(_next) {}
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

  ~List() { free(); }

  List(const List &other) {
    for (Node *ptr = other.head; ptr != nullptr; ptr = ptr->next) {
      push_back(ptr->data);
    }
  }

  List &operator=(const List &other) {
    if (this == &other) {
      return *this;
    }

    free();
    head = nullptr;

    for (Node *ptr = other.head; ptr != nullptr; ptr = ptr->next) {
      push_back(ptr->data);
    }
    return *this;
  }

  void display() {
    for (Node *ptr = head; ptr != nullptr; ptr = ptr->next) {
      std::cout << (*ptr).data << '\n';
    }
  }

  void push_back(int data) {
    Node **ptr = &head;
    while (*ptr != nullptr) {
      ptr = &(*ptr)->next;
    }

    *ptr = new Node{data, nullptr};
  }

  int length() {
    int length = 0;
    for (Node *ptr = head; ptr != nullptr; ptr = ptr->next) {
      length += 1;
    }
    return length;
  }
};

int main() {
  List l{};
  l.push_back(5);
  l.push_back(6);

  l.push_back(7);

  List l2(l);
  l2 = l;
  l2 = l2;

  l.display();
  std::cout << '\n';
  l2.display();
}
