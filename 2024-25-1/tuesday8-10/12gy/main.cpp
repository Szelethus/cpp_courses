#include "linked_list.h"
#include <string>

int main() {
  List<int> l;
  l.push_back(5);
  l.push_back(6);
  l.push_back(7);

  List<std::string> sl;
  sl.push_back("ALMA");
  sl.push_back("KORTE");

  List<int>::Iterator it = List<int>::Iterator(nullptr);

  List<int>::ConstIterator cit = it;
}
