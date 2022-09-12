#include "complex.h"

Complex::Complex(double re_, double im_) : re(re_), im(im_) {}

double Complex::getRe() const { return re; }
double Complex::getIm() const { return im; }

void Complex::setRe(double re_) { re = re_; }
void Complex::setIm(double im_) { im = im_; }
