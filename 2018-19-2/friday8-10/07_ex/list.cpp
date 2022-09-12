#include <iostream>

struct Node {
  int data;
  Node *next;

  Node(int data_) : data(data_), next(NULL) {}
};

class Iterator {
  Node *ptr;

public:
  Iterator(Node *ptr_) : ptr(ptr_) {}
  
  void operator++() {
    ptr = ptr->next;
  }

  // Iterator it, it2;
  // it == it2;
  // it.operator==(it2);
  bool operator==(const Iterator &other) {
    return ptr == other.ptr;
  }

  // Iterator it, it2;
  // it != it2;
  // it.operator!=(it2);
  bool operator!=(const Iterator &other) {
    return !(*this == other);
  } 

  int& operator*() {
    return ptr->data;
  }

  friend class ConstIterator;
};

class ConstIterator {
  const Node *ptr;

public:
  ConstIterator(Node *ptr_) : ptr(ptr_) {}
  ConstIterator(const Iterator &it) : ptr(it.ptr) {}
  
  void operator++() {
    ptr = ptr->next;
  }

  // ConstIterator it, it2;
  // it == it2;
  // it.operator==(it2);
  bool operator==(const ConstIterator &other) {
    return ptr == other.ptr;
  }

  // ConstIterator it, it2;
  // it != it2;
  // it.operator!=(it2);
  bool operator!=(const ConstIterator &other) {
    return !(*this == other);
  } 

  int operator*() {
    return ptr->data;
  }
};

class List {
  Node *head;

  void free() {
    Node *current = head;

    while (current != NULL) {
      Node *tmp = current->next;
      delete current;
      current = tmp;
    }
  }

  void copyElements(const List &other) {
    if (other.head == NULL)
      return;

    Node *ptr = other.head;

    while (ptr != NULL) {
      add(ptr->data);
      ptr = ptr->next;
    }
  }
  
public:
  List() : head(NULL) {}

  // másoló konstruktor
  List(const List &other) : head(NULL) {
    copyElements(other);
  }

  // értékadó operátor
  List &operator=(const List &other) {
    if (this == &other)
      return *this;

    free();
    head = NULL;
    copyElements(other);

    return *this;
  }

  void add(int newData) {
    if (head == NULL) {
      head = new Node(newData);
      return;
    }

    Node *ptr = head;

    while (ptr->next != NULL) {
      ptr = ptr->next;
    }

    ptr->next = new Node(newData);
  }

  ~List() {
    free();
  }

  void print() {
    Node *current = head;

    while (current != NULL) {
      std::cout << current->data << "->";
      current = current->next;
    }
    std::cout << "NULL\n";
  }

  Iterator begin() {
    return Iterator(head);
  }

  Iterator end() {
    return Iterator(NULL);
  }

  ConstIterator begin() const {
    return ConstIterator(head);
  }

  ConstIterator end() const {
    return ConstIterator(NULL);
  }
};

int main() {
  List l;

  l.add(5);
  l.add(6);

  // A ConstIterator második konstruktorával át tudunk konvertálni egy Iterator-
  // t ConstIterator-rá.
  // it != l.end() esetében is ez történik, hogy a ConstIterator != operátora
  // ConstIteratort vár paraméterül, de _implicit_ módon az l.end() Itarator
  // át fog konvertálódni ConstIterator-rá.
  for (ConstIterator it = l.begin(); it != l.end(); ++it) {
    std::cout << *it << ' ';
  }

  std::cout << '\n';
}

