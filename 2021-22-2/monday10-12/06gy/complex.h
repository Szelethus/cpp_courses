#ifndef _COMPLEX_H_
#define _COMPLEX_H_

struct Complex {
private:
  double re;
  double im;

public:
  Complex(double re_ = 0, double im_ = 0);

  double getRe() const;
  double getIm() const;

  void setRe(double re_);
  void setIm(double im_);
};

#endif
