#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <iosfwd>

//===-------------------------===//
// Iterator
//===-------------------------===//

template <class T> struct Node;

namespace list_detail {

// Forward iterator
template <class T> class Iterator {
  Node<T> *ptr;

public:
  explicit Iterator(Node<T> *_ptr) : ptr(_ptr) {}

  // ++Prefix operátor: ++it;
  Iterator operator++();
  // Postfix++
  Iterator operator++(int);

  bool operator==(Iterator other) { return ptr == other.ptr; }
  bool operator!=(Iterator other) { return !(*this == other); }
  T &operator*();

  template <class> friend class ConstIterator;
};

} // namespace list_detail

//===-------------------------===//
// ConstIterator
//===-------------------------===//

namespace list_detail {

// Forward iterator
template <class T> class ConstIterator {
  const Node<T> *ptr;

public:
  explicit ConstIterator(const Node<T> *_ptr) : ptr(_ptr) {}
  ConstIterator(Iterator<T> it) : ptr(it.ptr) {}

  ConstIterator operator++();
  bool operator==(ConstIterator other) { return ptr == other.ptr; }
  bool operator!=(ConstIterator other) { return !(*this == other); }
  const T &operator*();
};

} // namespace list_detail

//===-------------------------===//
// Node
//===-------------------------===//

template <class T> struct Node {
  T data;
  Node *next;

  Node(const T &_data, Node *_next) : data(_data), next(_next) {}
};

//===-------------------------===//
// List
//===-------------------------===//

template <class T> class List {
private:
  Node<T> *head = nullptr;

  void free();

  static int count;

public:
  List() { count++; };
  List(const List &other);
  List &operator=(const List &other);
  ~List() { free(); }

  using Iterator = list_detail::Iterator<T>;
  using ConstIterator = list_detail::ConstIterator<T>;

  void push_back(const T &data);

  // [begin(),
  Iterator begin() { return Iterator{head}; }
  // end())
  Iterator end() { return Iterator{nullptr}; }

  ConstIterator begin() const { return ConstIterator{head}; }
  ConstIterator end() const { return ConstIterator{nullptr}; }

  static int getCount() { return count; }

  int length() const;
};

template <class T>
std::ostream &operator<<(std::ostream &out, const List<T> &l);




























//===--------------===//
// Iterator
//===--------------===//

namespace list_detail {
template <class T> Iterator<T> Iterator<T>::operator++() {
  ptr = ptr->next;
  return *this;
}

template <class T> Iterator<T> Iterator<T>::operator++(int) {
  Iterator ret = *this;
  ++(*this);
  return ret;
}
template <class T> T &Iterator<T>::operator*() { return ptr->data; }

//===--------------===//
// ConstIterator
//===--------------===//

template <class T> ConstIterator<T> ConstIterator<T>::operator++() {
  ptr = ptr->next;
  return *this;
}
template <class T> const T &ConstIterator<T>::operator*() { return ptr->data; }
} // namespace list_detail

//===--------------===//
// List
//===--------------===//

template <class T> int List<T>::count = 0;

template <class T> void List<T>::free() {
  Node<T> *ptr = head;
  while (ptr != nullptr) {
    Node<T> *nextPtr = ptr->next;
    delete ptr;
    ptr = nextPtr;
  }
}

template <class T> List<T>::List(const List &other) {
  for (Node<T> *ptr = other.head; ptr != nullptr; ptr = ptr->next) {
    push_back(ptr->data);
  }
}

template <class T> List<T> &List<T>::operator=(const List &other) {
  if (this == &other)
    return *this;

  free();
  head = nullptr;

  for (Node<T> *ptr = other.head; ptr != nullptr; ptr = ptr->next) {
    push_back(ptr->data);
  }
  return *this;
}

template <class T> void List<T>::push_back(const T &data) {
  Node<T> **ptr = &head;
  while ((*ptr) != nullptr) {
    ptr = &(*ptr)->next;
  }
  *ptr = new Node<T>{data, nullptr};
}

template <class T> int List<T>::length() const {
  int length = 0;
  for (Node<T> *ptr = head; ptr != nullptr; ptr = ptr->next) {
    length++;
  }
  return length;
}

template <class T>
std::ostream &operator<<(std::ostream &out, const List<T> &l) {
  for (typename List<T>::ConstIterator it = l.begin(); it != l.end(); ++it) {
    out << *it << '\n';
  }
  return out;
}

#endif // __LINKED_LIST_H__
