#include <iostream>

struct Node {
  int data;
  Node *next;

  Node(int data_) : data(data_), next(NULL) {}
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

  // List l2 = l;
  // másoló konstruktor
  List(const List &other) : head(NULL) {
    copyElements(other);
  }

  // List l2;
  // l2 = l;
  // értékadó operátor
  List &operator=(const List &other) {
    if (this == &other)
      return *this;

    free();
    // A copyElements függvény meghívja az addot, ami külön esetként kezeli, ha
    // a lista üres. Mivel a free függvény (direkt!) nem állítja a head-et NULL-
    // ra, ezért ezt itt meg kell tennünk.
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
};

int main() {
  List l;

  l.add(5);
  l.add(6);

  l.print();

  {
    List l2;
    
    l2.add(54);

    l2 = l;

    l2.print();
  }

  l = l;

  // l destructora lefut
}
