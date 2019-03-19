#include <iostream>

struct List {
  int data;
  List *next;

  // konstruktor
  List(int dataParam) {
    data = dataParam;
    next = NULL;
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

void freeList(List &head) {
  List *current = head.next;

  while(current != NULL) {
    List *tmpnext = current->next;
    delete current;
    current = tmpnext;
  }

  head.next = 0;
}

int main() {
  List head(6);

  addElementToList(head, 6);
  addElementToList(head, 7);

  freeList(head);
}
