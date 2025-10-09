#include <iostream>

struct Node {
  int data;
  Node *next;
};

struct List {
  Node *head;

  void push_back(int data) {
    if (head == nullptr) {
      head = new Node{data, nullptr};
      return;
    }
    Node *ptr = head;
    while (ptr->next != nullptr)
      ptr = ptr->next;
    
    ptr->next = new Node{data, nullptr};
  }

  void display() {
    Node *ptr = head;
    while (ptr != nullptr) {
      std::cout << ptr->data << '\n';
      ptr = ptr->next;
    }
  }

  void free() {
    Node *ptr = head;
    while (ptr != nullptr) {
      Node *nextPtr = ptr->next;
      delete ptr;
      ptr = nextPtr;
    }
  }
};



int main() {
  List l{nullptr};
  l.push_back(5);
  l.push_back(6);
  l.push_back(7);

  l.display();

  l.free();
}
