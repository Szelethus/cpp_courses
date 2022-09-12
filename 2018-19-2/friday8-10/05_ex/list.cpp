#include <iostream>

struct List {
  int data;
  List *next;

  // konstruktor
  List(int dataParam)
    : data(dataParam), next(NULL) {}

  ~List() {
    delete next;
  }
};

void addElementToList(List &head, int data) {
  List *current = &head;

  while (current->next != NULL) {
    current = current->next;
  }

  // current az utolsó elemre mutat
  current->next = new List(data);
  current->next->next = NULL;
}

int main() {
  List head(6);

  addElementToList(head, 6);
  addElementToList(head, 7);
}
