#include <iostream>


int main()
{
  int capacity = 10;
  int *p = new int[capacity];
  int nread = 0;
  int k;

  while ( std::cin >> k )
  {
    if ( nread == capacity )
    {
      int *np = new int[2*capacity];

      for ( int i = 0; i < capacity; ++i)
	np[i] = p[i];
      delete [] p;
      p = np;
      capacity *= 2;    
    }
    p[nread++] = k;
  }
  std::cout << "capacity = " << capacity
	    << ", nread = "  << nread
	    << '\n';

  for ( int i = nread-1; i >= 0; --i)
  {
    std::cout << p[i] << ' ';
  }
  std::cout << '\n';
}
