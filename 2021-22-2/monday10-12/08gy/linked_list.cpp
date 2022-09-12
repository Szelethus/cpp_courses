#include <iostream>

struct Node {
  int data;
  Node *next;
};

void push_back(Node **param, int data) {
  if (*param == nullptr) {
    *param = new Node{data, nullptr};
    return;
  }

  Node *ptr = *param;
  while (ptr->next != nullptr) {
    ptr = ptr->next;
  }
  ptr->next = new Node{data, nullptr};
}

int main() {
  // üres láncolt lista
  Node *head = nullptr;

  push_back(&head, 2);
  push_back(&head, 3);
  push_back(&head, 4);
  push_back(&head, 5);

  Node *ptr = head;
  while (ptr != nullptr) {
    std::cout << ptr->data << '\n';
    ptr = ptr->next;
  }

  // TODO: DEALLOCATE!!!!

}
