#include <iostream>
#include <numeric>
#include "aecont.h"
#include <list>
#include <algorithm>
#include <set>
#include "aecont.h"

int max = 1000;


// Van neki egy insert, egyszer balra, egyszer jobbra szúr, van erase művelete
// ami ugyanilyen sorrendben töröl, at függvény balról jobbra indexel

int main()
{
  int your_mark = 1;



  alternating_endpoint_container<int> s;
  for( int i = 0; i < max; ++i )
  {
    s.insert( i );
  }

  alternating_endpoint_container<std::string> as;
  as.insert( "Hello" );
  as.insert( "World" );
  const alternating_endpoint_container<std::string> cas = as;

  alternating_endpoint_container<int> c;
  c.insert( 6 );
  c.insert( 2 );
  c.insert( 1 );
  c.insert( 4 );

  if ( 2 == cas.size() && "Hello" == cas.at( 0 ) &&
       6 == c.at( 1 ) && 1 == c.at( 0 ) &&
       max == s.size() && 1 == s.at( max / 2 ) &&
       max - 2 == s.at( 0 ) )
  {
    your_mark = c.at( 2 );
  }




  for( int i = 0; i < max / 2; ++i )
  {
    s.erase();
  }
  c.erase();
  c.erase();
  ++c[ 1 ];
  c[ 0 ] /= 2;

  if ( 2 == c.size() && max / 2 == s.size() &&
       c[ 0 ] == c[ 1 ] && "World" == cas[ 1 ] &&
       max / 2 - 2 == s[ 0 ] )
  {
    your_mark = c[ 0 ];
  }
  
  
  
  
  
  alternating_endpoint_container<int>::iterator it =
    std::max_element( s.begin(), s.end() );
  if ( (( max / 2 - 1 ) * ( max / 2 )) / 2 ==  std::accumulate( s.begin(), s.end(), 0 ) &&
       499 == *it )
  {
    your_mark = s[ max / 4 ] + c[ 1 ];
  }





  std::set<double> a;
  a.insert( 6.12 );
  a.insert( 1.11 );
  a.insert( 7.36 );

  std::list<int> b;
  b.push_back( 4 );
  b.push_back( 1 );
  b.push_back( 9 );

  alternating_endpoint_container<double> ea( a.begin(), a.end() );
  alternating_endpoint_container<double> eb( b.begin(), b.end() );

  if ( 3 == ea.size() && 1.5 > ea[ 1 ] )
  {
    your_mark = std::accumulate( eb.begin() + 1, eb.end(), 0 );
  }



  std::cout << "Your mark is "
            << your_mark;
  std::endl( std::cout );
}
