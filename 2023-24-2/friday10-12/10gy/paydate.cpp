#include <iostream>
#include "paydate.h"

void PayDate::print() const
{
  static const char* t[] = { "cash", "transfer", "card" };
  std::cout << "[ ";
  Date::print();
  std::cout << ", " << t[mode()] << "]";
}

