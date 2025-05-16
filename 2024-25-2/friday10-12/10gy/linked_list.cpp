#include "linked_list.h"

//===--------------------------------------------===//
// Iterator implementation
//===--------------------------------------------===//

namespace detail {
Iterator Iterator::operator++() {
  ptr = ptr->next;
  return *this;
}

Iterator Iterator::operator++(int) {
  Iterator prev = *this;
  ptr = ptr->next;
  return prev;
}

int& Iterator::operator*() {
  return ptr->data;
}
} // end of namespace detail

//===--------------------------------------------===//
// ConstIterator implementation
//===--------------------------------------------===//

detail::ConstIterator detail::ConstIterator::operator++() {
  ptr = ptr->next;
  return *this;
}

detail::ConstIterator detail::ConstIterator::operator++(int) {
  ConstIterator prev = *this;
  ptr = ptr->next;
  return prev;
}

int detail::ConstIterator::operator*() {
  return ptr->data;
}
