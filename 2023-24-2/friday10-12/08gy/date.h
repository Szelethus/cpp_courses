#ifndef DATE_H
#define DATE_H

class Date
{
public:
     Date(int year = 1970, int month = 1, int day = 1);	
  int year() const { return year_; }
  int month() const { return month_; }
  int day() const { return day_; }
  void set(int year, int month, int day);

  Date& operator++()    { next(); return *this; }
  Date  operator++(int) { Date old{*this};  next(); return old; }
  Date& operator+=(int n);
private:
  int year_;
  int month_;
  int day_;
  
  void next();
  void check(int year, int month, int day);
};


#endif // DATE_H
