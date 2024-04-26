#ifndef DATE_H
#define DATE_H

class Date
{
public:
   Date(int year = 1900, int month = 1, int day = 1);
   
   void set(int year = 1900, int month = 1, int day = 1);
   int  year() const { return year_; }
   int  month() const { return month_; }
   int  day() const { return day_; }

   Date& operator++() { next(); return *this; }
   Date& operator+=(int n);
private:
  int year_;
  int month_;
  int day_;
    
  void check(int year, int month, int day) const;
  void next();
};
bool operator==(const Date&, const Date& );

#endif // DATE_H
