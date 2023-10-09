#include <iostream>

struct Node {
  int data;
  Node *next;
};

int main() {
  Node *head = nullptr;
  head = new Node{5, nullptr};
  head->next = new Node{5, nullptr};
  head->next->next = new Node{5, nullptr};

  delete head->next->next;
  delete head->next;
  delete head;
}
