#include <iostream>

struct Node {
  int data;
  Node *next;
};

class LinkedList {
  Node *head;

public:
  LinkedList() : head(nullptr) {}

  LinkedList(const LinkedList &other) : head(nullptr) {
    if (other.head == nullptr)
      return;
    Node *ptr = other.head;
    while (ptr != nullptr) {
      this->push_back(ptr->data);
      ptr = ptr->next;
    }
  }

  LinkedList &operator=(const LinkedList &other) {
    // clear out the existing list
    deallocate();
    head = nullptr;

    Node *ptr = other.head;
    while (ptr != nullptr) {
      this->push_back(ptr->data);
      ptr = ptr->next;
    }
    
    return *this;
  }

  ~LinkedList() {
    deallocate();
  }

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
    // A lista üres!
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

  l.push_back(2);
  l.push_back(3);
  l.push_back(4);
  l.push_back(5);

  LinkedList l2 = l;
  l2 = l;
  l.display();
  l2.display();
}
