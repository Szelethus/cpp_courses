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
      Node *tmp = current->next;
      delete current;
      current = tmp;
    }
  }

  void copyElementsFromList(const List &other) {
    for (Node *ptr = other.head; ptr != nullptr; ptr = ptr->next) {
      add(ptr->data);
    }
  }

public:
  List() {
    head = nullptr;
  }

  void add(int data_) {
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

  // másoló konstruktor
  // List l2 = l; List l2(l);
  List(const List &other) {
    head = nullptr;
    copyElementsFromList(other);
  }

  // értékadó operátor
  // List l2; l2 = l;
  List & operator=(const List &other) {
    free();
    head = nullptr;
    copyElementsFromList(other);

    return *this;
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
  l.add(6);
  l.add(7);
  l.print();

  {
    List l2;
    l2.add(5);
    l2 = l;
    l2.print();
  }

}
