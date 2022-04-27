#include <iostream>

struct Node {
  int data;
  Node *next;
};

class LinkedList {
  Node *head = nullptr;

public:
  LinkedList() = default;

  LinkedList(const LinkedList &other) {
    copyFrom(other);
  }

  LinkedList &operator=(const LinkedList &other) {
    deallocate();
    head = nullptr;
    copyFrom(other);
    return *this;
  }

  void copyFrom(const LinkedList &other) {
    Node *ptr = other.head;
    while (ptr != nullptr) {
      this->push_back(ptr->data);
      ptr = ptr->next;
    }
  }

  ~LinkedList() { deallocate(); }

private:
  void deallocate() {
    Node *ptr = head;
    while (ptr != nullptr) {
      Node *nextNode = ptr->next;
      delete ptr;
      ptr = nextNode;
    }
  }

public:
  void push_back(int data) {
    if (head == nullptr) {
      head = new Node{data, nullptr};
      return;
    }

    Node *ptr = head;
    while (ptr->next != nullptr) {
      ptr = ptr->next;
    }
    ptr->next = new Node{data, nullptr};
  }

  void display() const {
    Node *ptr = head;
    while (ptr != nullptr) {
      std::cout << ptr->data << ' ';
      ptr = ptr->next;
    }
    std::cout << '\n';
  }
};

int main() {
  LinkedList l;

  l.push_back(1);
  l.push_back(2);
  l.push_back(3);
  l.push_back(4);
  l.push_back(5);

  LinkedList l2 = l;
   
  l2 = l;
  l2 = l;
  l2 = l;
  l2 = l;

  l.display();
  l2.display();
}
