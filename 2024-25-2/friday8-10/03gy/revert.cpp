#include <iostream>


int main()
{
  int capacity = 10;	
  int *t = new int[capacity];
  int nread = 0;
  int k;

  while ( std::cin >> k )
  {
    if ( capacity == nread )
    {
       int *np = new int[2*capacity];
       for ( int i = 0; i < capacity; ++i)
	   np[i] = t[i];
       delete [] t;
       t = np;
       capacity *= 2;
    }
    t[nread] = k;
    nread++;
  }
  std::cout << "capacity = " << capacity 
	    << ", nread "    << nread 
	    << '\n';
  for (int i = nread-1; i >= 0; --i)
  {
    std::cout << t[i] << ' ';
  }
  std::cout << '\n';

  return 0;
}

