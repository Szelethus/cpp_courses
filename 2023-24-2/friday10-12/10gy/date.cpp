#include <stdexcept>
#include <iostream>
#include "date.h"

namespace 
{
   int daysOfMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31};
}

void Date::set(int year, int month, int day)
{
  check(year,month,day);
  year_  = year;
  month_ = month;  
  day_   = day;
}

Date::Date(int year, int month, int day)
{
  set(year,month,day);
}

void Date::check(int year, int month, int day)
{ 
  if ( 0 == year  ||  month < 1 ||  month > 12  ||
       day < 0 || daysOfMonth[month-1] < day )
    throw std::out_of_range{"Bad date"};
}

void Date::next()
{
  ++day_;
  if ( day_ > daysOfMonth[month_-1] )
  {
    day_ = 1;
    ++month_;
  }
  if ( month_ > 12 )
  {
    month_ = 1;
    ++year_;    
  }
  if ( 0 == year_ )
  {
    ++year_;	  
  }	  
}
Date& Date::operator+=(int n)
{
  for ( int i = 0; i < n; ++i)
  {
    next();	  
  }	  
  return *this;
}
void Date::print() const
{
  std::cout << "[ " << year() << ", "
		    << month() << ", "
		    << day() << "]";
}
