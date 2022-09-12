#include <iostream>

struct Node {
  int data;
  Node *next;

  Node() {
    data = 0;
    next = nullptr;
  }

  void add(int data_) {
    Node *ptr = this;

    while (ptr->next != nullptr) {
      ptr = ptr->next;
    }

    ptr->next = new Node;
    ptr->next->data = data_;
    ptr->next->next = nullptr;
  }


  void free() {
    Node *current = this->next;
    
    while (current != nullptr) {
      Node *next = current->next;
      delete current;
      current = next;
    }
  }
};

int main() {
  Node head;
  head.data = 5;
  head.next = nullptr;
  
  head.add(7);
  head.add(10);

  head.free();

}
