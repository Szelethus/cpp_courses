#ifndef __LIST_H__
#define __LIST_H__

struct Node {
  int data;
  Node *next;

  Node(int data_) : data(data_), next(nullptr) {}
};

class Iterator {
  Node *ptr;

public:
  Iterator(Node *ptr_) : ptr(ptr_) {}

  void operator++() {
    ptr = ptr->next;
  }

  // Iterator it1, it2;
  // it1 == it2;
  bool operator==(const Iterator &it) {
    return ptr == it.ptr;
  }

  bool operator!=(const Iterator &it) {
    return !(*this == it);
  }

  // Iterator it1;
  // *it1;
  int &operator*() {
    return ptr->data;
  }
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

  void copyElements(const List &other) {
    if (other.head == nullptr) {
      return;
    }

    for (Node *ptr = other.head; ptr != nullptr;
                                        ptr = ptr->next) {
      add(ptr->data);
    }
  }

public:
  List() : head(nullptr) {}

  List(int size) : head(nullptr) {
    for (int i = 0; i < size; ++i)
      add(0);
  }

  // List l2 = l; List l2(l);
  // ez fog meghivásra kerülni
  List(const List &other) {
    head = nullptr;
    copyElements(other);
  }

  // List l, l2;
  // l2 = l;
  // értékadó operátor kerül meghvásra
  List &operator=(const List &other) {
    if (this == &other)
      return *this;

    free();
    head = nullptr;
    copyElements(other);
    
    return *this;
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

  void print() const;

  Iterator begin() {
    return Iterator(head);
  }

  Iterator end() {
    return Iterator(nullptr);
  }
};

#endif // __LIST_H__
