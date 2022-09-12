#include <iostream>

struct Node {
  int data;
  Node *next;

  Node(int data_) : data(data_), next(nullptr) {}
};

class List {
  Node *head;

  void free() {
    Node *current = head;
    
    while (current != nullptr) {
      Node *next = current->next;
      delete current;
      current = next;
    }
  }   

public:
  List() {
    head = nullptr;
  }

  // List l2 = l; List l2(l);
  // ez fog meghivásra kerülni
  List(const List &other) {
    head = nullptr;
    
    if (other.head == nullptr) {
      return;
    }

    for (Node *ptr = other.head; ptr != nullptr;
                                        ptr = ptr->next) {
      add(ptr->data);
    }
  }

  void add(int data_) {
    // hogyha ez a lista még üres, akkor...
    if (head == nullptr) {
      head = new Node(data_);
      return;
    }

    Node *ptr = head;

    while (ptr->next != nullptr) {
      ptr = ptr->next;
    }

    ptr->next = new Node(data_);
  }

  ~List() {
    free();
  }

  void print() {
    for (Node *ptr = head; ptr != nullptr; ptr = ptr->next) {
      std::cout << ptr->data << "->";
    }
    std::cout << "NULL\n";
  }
};

int main() {
  List l;
  l.add(5);
  l.add(7);
  l.add(8);
  l.add(9);

  {
    List l2 = l;
    l2.print();
  }
  l.print();
}
