struct Node {
  int data;
  Node *next;
};

void push_back(Node **head, int data) {
  if (*head == nullptr)  {
    *head = new Node{data, nullptr};
    return;
  }

  Node *ptr = *head;

  while (ptr->next != nullptr) {
    ptr = ptr->next;
  }

  ptr->next = new Node{data, nullptr};
} 

int main() {
  Node *head0 = nullptr;

  push_back(&head0, 1);
  push_back(&head0, 2);
  push_back(&head0, 3);

  delete head0->next->next;
  delete head0->next;
  delete head0;
}
