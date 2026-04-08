#include "linked_list.h"

//===----------------------------------------===//
// Iterator implementation
//===----------------------------------------===//
//prefix++
template <class T>
Iterator<T> Iterator<T>::operator++() {
  ptr = ptr->next;
  return *this;
}

//++postfix
template <class T>
Iterator<T> Iterator<T>::operator++(int) {
  Iterator ret = *this;
  ptr = ptr->next;
  return ret;
}

template <class T>
T &Iterator<T>::operator*() {
  return ptr->data;
}

//===----------------------------------------===//
// ConstIterator implementation
//===----------------------------------------===//
//prefix++
template <class T>
ConstIterator<T> ConstIterator<T>::operator++() {
  ptr = ptr->next;
  return *this;
}

//++postfix
template <class T>
ConstIterator<T> ConstIterator<T>::operator++(int) {
  ConstIterator ret = *this;
  ptr = ptr->next;
  return ret;
}

template <class T>
const T &ConstIterator<T>::operator*() {
  return ptr->data;
}

//===----------------------------------------===//
// List implementation
//===----------------------------------------===//

// másoló konstruktor
template <class T>
List<T>::List(const List &other) {
  Node<T> *ptr = other.head;
  while (ptr != nullptr) {
    push_back(ptr->data);
    ptr = ptr->next;
  }
}

// értékadó operátor
template <class T>
List<T> &List<T>::operator=(const List &other) {
  if (this == &other)
    return *this;

  free();
  head = nullptr;

  Node<T> *ptr = other.head;
  while (ptr != nullptr) {
    push_back(ptr->data);
    ptr = ptr->next;
  }

  return *this;
}

template <class T>
void List<T>::push_back(const T &data) {
  Node<T> **ptr = &head;

  while (*ptr != nullptr)
    ptr = &(*ptr)->next;

  *ptr = new Node{data, nullptr};
}

// konstans tagfüggvény
template <class T>
void List<T>::print() const {
  Node<T> *ptr = head;
  while (ptr != nullptr) {
    std::cout << ptr->data << '\n';
    ptr = ptr->next;
  }
}

template <class T>
void List<T>::print2() {
  for (Iterator it = begin(); it != end(); ++it) {
    std::cout << *it << '\n';
  }
}

template <class T>
void List<T>::free() {
  Node<T> *ptr = head;

  while (ptr != nullptr) {
    Node<T> *nextPtr = ptr->next;
    delete ptr;
    ptr = nextPtr;
  }
}
