#include "poscomplex.h"
#include <cassert>

PosComplex::PosComplex(double re_, double im_)
    : orig_re(re_), orig_im(im_), re(re_), im(im_) {
  assert(re > 0 && "Real component is negative!\n");
  assert(im > 0 && "Im component is negative!\n");
}

double PosComplex::getRe() const { return re; }
double PosComplex::getIm() const { return im; }

void PosComplex::setRe(double re_) {
  assert(re_ > 0 && "Negative number given to setRe!");
  re = re_;
}

void PosComplex::setIm(double im_) {
  assert(im_ > 0 && "Negative number given to setRe!");
  im = im_;
}
