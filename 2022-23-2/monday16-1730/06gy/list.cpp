#include <iostream>

struct Node {
  int data;
  Node *next;

  Node(int data, Node *next = nullptr) : data(data), next(next) {}
};

class List {
  Node *head = nullptr;

public:
  void add(int data) {
    if (head == nullptr) {
      head = new Node(data);
      return;
    }

    Node *ptr = head;
    while (ptr->next != nullptr) {
      ptr = ptr->next;
    }
    ptr->next = new Node(data);
  }

  void free() {
    Node *ptr = head;
    while (ptr != nullptr) {
      Node *nextPtr = ptr->next;
      delete ptr;
      ptr = nextPtr;
    }
  }

  void print() {
    for (Node *ptr = head; ptr != nullptr; ptr = ptr->next)
      std::cout << ptr->data << '\n';
  }
};

int main() {
  List l;
  l.add(5);
  l.add(6);
  l.add(7);
  l.add(7);
  l.add(7);
  l.add(7);
  l.add(7);
  l.print();

  l.free();
}
