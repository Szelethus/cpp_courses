#include <iostream>

struct Node {
  int data;
  Node *next;
};

class List {
  Node *head;

public:
  List() : head(nullptr) {}

  void push_back(int data) {
    if (head == nullptr) {
      head = new Node{data, nullptr};
    }

    Node *ptr = head;
    while (ptr->next != nullptr)
      ptr = ptr->next;
    ptr->next = new Node{data, nullptr};
  }

  void display() {
    Node *ptr = head;
    while (ptr != nullptr) {
      std::cout << ptr->data << ' ';
      ptr = ptr->next;
    }
  }
};

int main() {
  List l;
  l.push_back(2);
  l.push_back(2);
  l.push_back(2);
  l.push_back(2);
  l.display();
}
