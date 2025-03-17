#include <iostream>
#include <vector>

int main()
{
  std::vector<int> v;
  int k;

  while ( std::cin >> k )
  {
     v.push_back(k);
  }
  std::cout << "capacity = " << v.capacity()
	    << ", size = "   << v.size()
	    << '\n';

  for ( int i = v.size()-1; i >= 0; --i)
  {
    std::cout << v[i] << ' ';
  }
  std::cout << '\n';
}
