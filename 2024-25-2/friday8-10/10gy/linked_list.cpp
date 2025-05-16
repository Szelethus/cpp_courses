#include "linked_list.h"

//===-------------------------------------------===//
// Iterator implementation
//===-------------------------------------------===//

namespace detail {
// member function definition
// ++it (++prefix)
Iterator Iterator::operator++() {
  ptr = ptr->next;
  return *this;
}

// it++ (postfix++)
Iterator Iterator::operator++(int) {
  Iterator prev = *this;
  ptr = ptr->next;
  return prev;
}

int& Iterator::operator*() {
  return ptr->data;
}
} // namespace detail

//===-------------------------------------------===//
// ConstIterator implementation
//===-------------------------------------------===//

// member function definition
// ++it (++prefix)
detail::ConstIterator detail::ConstIterator::operator++() {
  ptr = ptr->next;
  return *this;
}

// it++ (postfix++)
detail::ConstIterator detail::ConstIterator::operator++(int) {
  ConstIterator prev = *this;
  ptr = ptr->next;
  return prev;
}

int detail::ConstIterator::operator*() {
  return ptr->data;
}
