#include <iostream>
#include "date.h"

void print(Date d) 
{
  std::cout << "[" << d.year()  << ", "
	           << d.month() << ", "
	           << d.day() << "]\n";
}

int main()
{
  Date  d1{2024,4,19};
  Date  d2{2024,5};
  const Date  d3{2024};
  Date  d4{};
  Date  d5{2024,2,30};

  print(d1);
  d1.set(2025,4); 
  print(d1);
  
  ++d1;
  print(d1);

  d1+=42; 
  print(d1);
/*
  if ( d1 == d3 )
    std::cout << " d1 == d3" << '\n';
  if ( d2 > d4 )
    std::cout << " d2 > d4" << '\n';
  */ 
  return 0;
}
