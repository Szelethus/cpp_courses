#include <set>
#include <iostream>
#include "setfilter.h"
#include <string>
#include "setfilter.h"

struct is_even: std::unary_function<int, bool>
{

  bool operator()( int i ) const
  {
    return 0 == i % 2;
  }

};

struct is_small: std::unary_function<int, bool>
{

  bool operator()( int i ) const
  {
    return i < 4;
  }

};

struct is_kind : std::unary_function<std::string, bool>
{

  bool operator()( const std::string& s ) const
  {
    return "Hello" == s;
  }

};

struct is_good_language : std::unary_function<std::string, bool>
{

  bool operator()( const std::string& s ) const
  {
    return "C++" == s;
  }

};

struct string_size_less: std::binary_function<std::string, std::string, bool>
{

  bool operator()( const std::string& a,
                   const std::string& b ) const
  {
    return a.size() < b.size();
  }

};

const int max = 1000;

int main()
{
  int your_mark = 1;
  std::set<std::string> sst;
  sst.insert( "Hello" );
  sst.insert( "World" );
  set_filtering<std::string> sstf( sst );
  sstf.filter( "World" );
  sstf.filter( "No such string" );
  sstf.unfilter( "World" );
  sstf.filter( "Hello" );

  std::set<int> smx;
  for( int i = 0; i < max; ++i )
  {
    smx.insert( i );
  }
  set_filtering<int> smxf( smx );
  smxf.filter( max / 2 );
  smxf.filter( max );
  smxf.filter( 0 );
  smxf.filter( 1 );
  smxf.unfilter( 1 );
  smxf.unfilter( 2 * max );
  if ( max - 2 == smx.size() && 0 == smx.count( max / 2 ) &&
       1 == sst.size() && 1 == sst.count( "World" ) )
  {
    your_mark = smx.count( 1 ) + smx.count( max - 1 );
  }





  smxf.inverse();
  sstf.inverse();
  sstf.inverse();

  std::set<int> ti;
  ti.insert( 7 );
  ti.insert( 2 );
  bool empty = ti.empty();

  if ( 2 == smx.size() && 1 == smx.count( 0 ) && 0 == smx.count( 3 ) )
  {
    set_filtering<int> tif( ti );
    tif.filter( 7 );
    tif.filter( 2 );
    empty = ti.empty();
  }
  if ( empty && !ti.empty() && 1 == sst.count( "World" ) &&
       1 == ti.count( 7 ) )
  {
    your_mark = *(ti.begin()) + sst.size();
  }









  ~smxf;
  ~sstf;

  smxf += is_even();
  smxf += is_small();
  sstf += is_kind();

  ti.insert( 6 );

  bool f = 1 == ti.size();

  if ( sst.empty() && 0 == smx.count( max / 4 ) )
  {
    set_filtering<int> tif( ti );
    tif += is_even();
    f = 1 == ti.size() && 1 == ti.count( 7 );
  }

  if ( f && 3 == ti.size() && 1 == ti.count( 6 ) )
  {
    your_mark = *(smx.begin()) - smx.count( max - 1 );
  }




  /* 5-os
  std::set<std::string, string_size_less> langs;
  langs.insert( "C++" );
  langs.insert( "C#" );
  langs.insert( "Cobol" );
  langs.insert( "Java" );
  set_filtering<std::string, string_size_less> lf( langs );

  lf.filter( "WTF?" );
  lf.filter( "SQL" );
  lf -= is_good_language();

  smxf -= is_even();

  if ( 1 == smx.count( max / 4 ) && 1 == langs.count( "C++" ) &&
       max / 2 < smx.size() && 0 == langs.count( "Java" ) )
  {
    your_mark = langs.size() + langs.begin()->size();
  }
  */
  std::cout << "Your mark is " << your_mark;
  std::endl( std::cout );
}
