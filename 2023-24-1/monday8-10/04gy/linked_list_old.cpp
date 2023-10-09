#include <iostream>

struct Node {
  int data;
  Node *next;
};

int main() {
  Node *head = nullptr;
  head = new Node{5, nullptr};
  // head->next == (*head).next
  head->next = new Node{6, nullptr};
  head->next->next = new Node{7, nullptr};

  delete head->next->next;
  delete head->next;
  delete head;
}
