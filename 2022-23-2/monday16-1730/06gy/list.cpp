#include <iostream>

struct Node {
  int data;
  Node *next;

  Node(int _data) {
    data = _data;
    next = nullptr;
  }
};

class List {
  Node *head = nullptr;

public:
  ~List() {
    free();
  }

  void push_back(int data) {
    if (head == nullptr) {
      head = new Node(data);
      return;
    }

    Node *ptr = head;
    
    while (ptr->next != nullptr) {
      ptr = ptr->next;
    }

    ptr->next = new Node(data);
  }

  void display() {
    Node *ptr = head;
    while (ptr != nullptr) {
      std::cout << ptr->data << '\n';
      ptr = ptr->next;
    }
  }

private:
  void free() {
    Node *ptr = head;
    while (ptr != nullptr) {
      Node *nextptr = ptr->next;
      delete ptr;
      ptr = nextptr;
    }
  }
};

int main() {
  List l;
  l.push_back(5);
  l.push_back(6);
  l.push_back(7);

  l.display();
}
