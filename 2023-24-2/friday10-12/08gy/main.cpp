#include <iostream>
#include "date.h"

void print(Date d)
{
  std::cout << "[ " 
	    << d.year() << ", "
	    << d.month() << ", "
	    << d.day() << "]\n"; 
}
int main()
{
  Date d1{2024,4,19};
  Date d2{2024,5};
  const Date d3{2025};
  Date d4{};  

  print(d1);
  ++d1;
  print(d1); 
  d2 = d4 += 40;
  print(d2);
  print(d4);
   
  try
  {
    d1.set(2025,2,28);
    print(d1);

    d1.set(2025,2,30);
  }
  catch(std::exception &e)
  {
    std::cout << e.what() << '\n';	  
  }
  return 0;
}


