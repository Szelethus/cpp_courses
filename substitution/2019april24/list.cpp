#include <iostream>

struct Node {
  int data;
  Node *next;

  Node(int data_) {
    data = data_;
    next = NULL;
  }
};

struct List {
  Node *head;

  List() {
    this->head = NULL;
  }

  void add(int data_) {
    if (head == NULL) {
      head = new Node(data_);
      return;
    }

    Node *ptr = head;

    while (ptr->next != NULL) {
      ptr = ptr->next;
    }

    ptr->next = new Node(data_);
  }

  ~List() {
    Node *current = head;

    while (current != NULL) {
      Node *tmp = current->next;
      delete current;
      current = tmp;
    }
  }

  // copy kontruktor
  // List l;
  // List l2 = l;
  // Itt ugyebár az 'l' lesz az 'other'
  List(const List &other) {
    Node *ptr = other.head;

    while (ptr != NULL) {
      this->add(ptr->data);
      ptr = ptr->next;
    }
  }
};

int main() {
  List l;
  l.add(5);
  l.add(6);
  l.add(7);
  l.add(8);
  l.add(9);

  {
    List l2 = l;
  } // l2 destruktora lefut

} // l destruktora lefut
