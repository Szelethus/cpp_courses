#include <iostream>

struct Node {
  int data;
  Node *next;
};

class List {
  Node *head;

public:
  ~List() {
  }

  void push_back(int data) {
    Node **ptr = &head;
    while ((*ptr) != nullptr) {
      ptr = &(*ptr)->next;
    }
    *ptr = new Node{data, nullptr};
  }

  void display() {
    Node *ptr = head;
    while (ptr != nullptr) {
      std::cout << ptr->data << '\n';
      ptr = ptr->next;
    }
  }
};

int main() {
  List l;
  l.push_back(1);
  l.display();

}
