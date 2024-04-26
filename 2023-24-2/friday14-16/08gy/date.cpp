
#include "date.h"

namespace
{
  int daysOfMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31};
}

void Date::set(int year, int month, int day)
{
  check(year, month, day);
  year_ = year;
  month_ = month;
  day_ = day;
}

Date::Date(int year, int month, int day)
{
  set(year,month,day);
}

void Date::check(int year, int month, int day) const
{
  // implement later
}
Date& Date::operator+=(int n)
{
  for(int i = 0; i<n; ++i)
  {
    operator++(); // ++*this
  }
  return *this;
}

void Date::next()
{
  ++day_;
  if ( daysOfMonth[month_-1] < day_ )
  {
    ++month_;
    day_ = 1;
  }
  if ( 13 == month_ )
  {
    ++year_;
    month_ = 1;
  }
  if ( 0 == year_ )
  {
    ++year_;
  }
}
