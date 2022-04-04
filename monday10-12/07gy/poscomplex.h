#ifndef _POSCOMPLEX_H_
#define _POSCOMPLEX_H_

#include <iosfwd>

class PosComplex {
  const double orig_re;
  const double orig_im;
  double re;
  double im;

public:
  PosComplex(double re_, double im_);

  double getRe() const;
  double getIm() const;

  void setRe(double re_);
  void setIm(double im_);

  friend std::ostream &operator<<(std::ostream &out,
                                  const PosComplex this_);
  friend class Complex;
};

#endif
