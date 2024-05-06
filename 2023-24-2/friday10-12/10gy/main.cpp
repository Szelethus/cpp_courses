#include <iostream>
#include <vector>
#include "date.h"
#include "paydate.h"

int main()
{
  std::vector<Date*> v;
  v.push_back(new PayDate{2024,4,19,PayDate::transfer});
  v.push_back(new Date{2024,5});
  v.push_back(new PayDate{2025});
  v.push_back(new PayDate{});
  v.push_back(new Date{});

  for ( auto ap : v )
  {
    ap->print();
  }
  for ( auto ap : v )
    delete ap;
  return 0;
}


