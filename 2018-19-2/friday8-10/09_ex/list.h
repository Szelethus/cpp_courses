#ifndef __LIST_H__
#define __LIST_H__

#include <iostream>

template <class T>
struct Node {
  T data;
  Node<T> *next;

  Node(int data_) : data(data_), next(NULL) {}
};

template <class T>
class Iterator {
  Node<T> *ptr;

public:
  Iterator(Node<T> *ptr_) : ptr(ptr_) {}

  void operator++() { ptr = ptr->next; }
  bool operator==(const Iterator<T> &other) { return ptr == other.ptr; }
  bool operator!=(const Iterator<T> &other) { return !(*this == other); }
  T &operator*() { return ptr->data; }

  template <class R>
  friend class ConstIterator;
};

template <class T>
class ConstIterator {
  const Node<T> *ptr;

public:
  ConstIterator(const Node<T> *ptr_) : ptr(ptr_) {}
  ConstIterator(const Iterator<T> &other) : ptr(other.ptr) {}

  void operator++() { ptr = ptr->next; }
  bool operator==(const ConstIterator<T> &other) { return ptr == other.ptr; }
  bool operator!=(const ConstIterator<T> &other) { return !(*this == other); }
  T operator*() { return ptr->data; }
};

template <class T>
class List {
  Node<T> *head;

  void free();
  void copyElements(const List<T> &other);

public:
  List() : head(NULL) {}
  explicit List(int size);

  List(const List<T> &other) : head(NULL) { copyElements(other); }
  List &operator=(const List<T> &other);
  ~List() { free(); }

  Iterator<T> begin() { return Iterator<T>(head); }
  Iterator<T> end() { return Iterator<T>(NULL); }

  ConstIterator<T> begin() const { return ConstIterator<T>(head); }
  ConstIterator<T> end() const { return ConstIterator<T>(NULL); }

  void add(int newData);
};

template <class T>
std::ostream& operator<<(std::ostream &out, const List<T> &l);

template <class T>
void List<T>::free() {
  Node<T> *current = head;

  while (current != NULL) {
    Node<T> *tmp = current->next;
    delete current;
    current = tmp;
  }
}

template <class T>
void List<T>::copyElements(const List<T> &other) {
  if (other.head == NULL)
    return;

  Node<T> *ptr = other.head;

  while (ptr != NULL) {
    add(ptr->data);
    ptr = ptr->next;
  }
}

template <class T>
List<T>::List(int size) : head(NULL) {
  for (int i = 0; i < size; i++)
    add(0);
}

template <class T>
List<T> &List<T>::operator=(const List<T> &other) {
  if (this == &other)
    return *this;

  free();
  head = NULL;
  copyElements(other);

  return *this;
}

template <class T>
void List<T>::add(int newData) {
  if (head == NULL) {
    head = new Node<T>(newData);
    return;
  }

  Node<T> *ptr = head;

  while (ptr->next != NULL) {
    ptr = ptr->next;
  }

  ptr->next = new Node<T>(newData);
}

template <class T>
std::ostream& operator<<(std::ostream &out, const List<T> &l) {
  for (auto it = l.begin(); it != l.end(); ++it) {
    std::cout << *it << "->";
  }
  std::cout << "NULL\n";

  return out;
}

#endif // __LIST_H__
