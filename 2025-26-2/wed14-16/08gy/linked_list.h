#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

// class forward declaration
template <class T>
struct Node;

//===----------------------------------------===//
// Iterator
//===----------------------------------------===//

// Mutató (Node *) általánosítása 
template <class T>
class Iterator {
  Node<T> *ptr;

public:
  Iterator(Node<T> *ptr) : ptr(ptr) {}

  //prefix++
  Iterator operator++();
  //++postfix
  Iterator operator++(int);
  T &operator*();
  bool operator==(Iterator other) {
    return ptr == other.ptr;
  }
  bool operator!=(Iterator other) {
    return !(*this == other);
  }
  template <class R>
  friend class ConstIterator;
};

//===----------------------------------------===//
// ConstIterator
//===----------------------------------------===//

// Konstansra mutató mutató (const Node *)
// általánosítása 
template <class T>
class ConstIterator {
  const Node<T> *ptr;

public:
  ConstIterator(const Node<T> *ptr) : ptr(ptr) {}
  // konverziós konstruktor
  ConstIterator(Iterator<T> it) : ptr(it.ptr) {}
  //prefix++
  ConstIterator operator++();
  //++postfix
  ConstIterator operator++(int);
  const T &operator*();
  bool operator==(ConstIterator other) {
    return ptr == other.ptr;
  }
  bool operator!=(ConstIterator other) {
    return !(*this == other);
  }
};

//===----------------------------------------===//
// Node
//===----------------------------------------===//
template <class T>
struct Node {
  T data;
  Node *next;
};

//===----------------------------------------===//
// List
//===----------------------------------------===//
template <class T>
class List {
  Node<T> *head = nullptr;

public:
  // konstruktor
  List() {}

  using Iterator = Iterator<T>;
  using ConstIterator = ConstIterator<T>;

  Iterator begin() { return Iterator{head}; }
  Iterator end() { return Iterator{nullptr}; }

  ConstIterator begin() const { return {head}; }
  ConstIterator end() const { return {nullptr}; }

  // másoló konstruktor
  List(const List &other);
  // értékadó operátor
  List& operator=(const List &other);
  // destruktor
  ~List() { free(); }

  void push_back(const T &data);
  // konstans tagfüggvény
  void print() const;
  void print2();

private:
  void free();
}; // end of class List

#endif // LINKED_LIST_H
