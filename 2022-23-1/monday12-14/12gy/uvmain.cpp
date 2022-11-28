#include <numeric>
#include <iostream>
#include <functional>
#include "unsvec.h"
#include <string>
#include "unsvec.h"
#include <algorithm>

struct string_size_less
{

  bool operator()( const std::string& a, const std::string& b ) const
  {
    return a.size() < b.size();
  }

};

const int max = 128;

struct pred
{

  bool operator()( const std::string& s ) const
  {
    return s.size() % max != 0;
  }

};

int main()
{
  int your_mark = 1;
  /* 2-es
  const std::string a[] = {"Java", "C++", "Fortran"};
  const unsortable_vector<std::string> cvs( a, sizeof( a ) / sizeof( a[ 0 ] ) );
  unsortable_vector<std::string> vs( a, sizeof( a ) / sizeof( a[ 0 ] ) );

  const int v[] = { 7, 1, 8, 4 };
  unsortable_vector<int> s ( v, sizeof( v ) / sizeof( v[ 0 ] ) );

  for( int i = 0; i < max; ++i )
  {
    s.set_sort_on().set_sort_off();
  }

  vs.set_sort_on().set_sort_off().set_sort_on();
  if ( 3 == cvs.size() && "C++" == vs.at( 0 ) &&
      cvs.at( 0 ) == vs.at( 2 ) && "Fortran" == cvs.at( 2 ) &&
      !cvs.is_sorted() && vs.is_sorted() )
  {
    your_mark = s.at( 3 ) + s.at( 0 ) - s.at( 1 ) - s.at( 2 );
  }
  */
  /* 3-as
  vs.set_sort_off().set_sort_on( string_size_less() );
  s.set_sort_on( std::greater<int>() );

  if ( 8 == s[ 0 ] && 4 == s[ 2 ] && 4 == s.size() )
  {
    your_mark = cvs[ 1 ].size();
  }
  */
  /* 4-es
  s.set_sort_off();
  const std::string b[] = {"C", "Ada"};
  unsortable_vector<std::string> ap( b, sizeof( b ) / sizeof( b[ 0 ] ) );

  vs += ap;
  ap += cvs;
  unsortable_vector<std::string> vsa = vs;
  vsa.set_sort_off();

  if ( 5 == ap.size() && "C++" == ap[ 3 ] && "Ada" == vs[ 0 ] &&
       "C++" == vs[ 2 ] && 5 == vsa.size())
  {
    your_mark = s[ 3 ];
  }
  */
  /* 5-os
  vsa.set_sort_on();
  unsortable_vector<std::string>::const_iterator i = std::find( vsa.begin(), vsa.end(), "C" );
  ++i;

  if ( 20 == std::accumulate( s.begin(), s.end(), 0 ) && "C++" == *i &&
       7 == *(s.begin() ) && "Java" == *(cvs.begin() ) )
  {
    your_mark = std::count_if( vsa.begin(), vsa.end(), pred() );
  }
  */
  std::cout << "Your mark is " << your_mark;
  std::endl( std::cout );
}
