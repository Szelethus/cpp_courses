#include <iostream>

struct Node {
  int data;
  Node *next;

  Node(int data_) {
    data = data_;
    next = NULL;
  }

  void add(int data_) {
    Node *ptr = this;

    while (ptr->next != NULL) {
      ptr = ptr->next;
    }

    ptr->next = new Node(data_);
  }

  ~Node() {
    delete next;
  }
};

int main() {
  Node head(6);

  head.add(7);
  head.add(8);
}
