#ifndef PAYDATE_H
#define PAYDATE_H

#include "date.h"

class PayDate : public Date
{
public:
  enum PayMode { cash, transfer, card };
  PayDate( int y = 2000, int m = 1, int d = 1, 
           PayMode p = cash) : Date(y,m,d), mode_(p) { }
  PayMode mode() const { return mode_; }
  void mode(PayMode p) { mode_ = p; }
  virtual void print() const override;
private:
  PayMode mode_;
};



#endif // PAYDATE_H
