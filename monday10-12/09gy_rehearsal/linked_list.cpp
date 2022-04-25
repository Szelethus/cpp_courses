#include <cstdlib>
#include <iostream>

struct Node {
  int data;
  Node *next = nullptr;

  Node(int data) : data(data) {}
};

class LinkedList {
  Node *head = nullptr;

  void deallocate(Node *param) {
    if (param == nullptr) {
      return;
    }
    deallocate(param->next);
    delete param;
  }

public:
  ~LinkedList() { deallocate(head); }

  void push_back(int data) {
    if (head == nullptr) {
      head = new Node{data};
      return;
    }

    Node *ptr = head;

    while (ptr->next != nullptr)
      ptr = ptr->next;

    ptr->next = new Node{data};
  }

  void display() {
    const Node *ptr = head;
    while (ptr != nullptr) {
      std::cout << ptr->data << ' ';
      ptr = ptr->next;
    }
    std::cout << '\n';
  }
};

int main() {
  LinkedList l;

  l.push_back(2);
  l.push_back(2);
  l.push_back(3);
  l.push_back(5);
  l.push_back(7);
  l.push_back(8);
  l.push_back(2);

  l.display();
}
