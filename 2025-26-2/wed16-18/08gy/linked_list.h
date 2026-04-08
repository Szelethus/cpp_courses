#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <algorithm>
#include <iostream>

// osztály deklaráció
struct Node;

//===-------------------------------------===//
// Iterator
//===-------------------------------------===//

// Mutatók (Node *) általánosítása
class Iterator {
  Node *ptr;

public:
  explicit Iterator(Node *ptr) : ptr(ptr) {}
  // ++it;
  Iterator operator++();
  // it++
  Iterator operator++(int);
  int &operator*();
  bool operator==(Iterator other) {
    return ptr == other.ptr;
  }
  bool operator!=(Iterator other) {
    return !(*this == other);
  }
  friend class ConstIterator;
};

//===-------------------------------------===//
// ConstIterator
//===-------------------------------------===//

// Konstansra mutató mutatók (const Node *)
// általánosítása
class ConstIterator {
  const Node *ptr;

public:
  ConstIterator(const Node *ptr) : ptr(ptr) {}
  // konverziós konstruktor
  ConstIterator(Iterator other) : ptr(other.ptr) {}
  // ++it;
  ConstIterator operator++();
  // it++
  ConstIterator operator++(int);
  int operator*();
  bool operator==(ConstIterator other) {
    return ptr == other.ptr;
  }
  bool operator!=(ConstIterator other) {
    return !(*this == other);
  }
};

//===-------------------------------------===//
// Node
//===-------------------------------------===//

struct Node {
  int data;
  Node *next;
};

//===-------------------------------------===//
// List
//===-------------------------------------===//
class List {
  Node *head = nullptr;

public:
  // konstruktor
  List() {}

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

  void push_back(int data);
  void print() const;
  void print2();

private:
  void free();
};


#endif //LINKED_LIST_H
