#include "funcao.hpp"
#ifndef SENOIDE_H
#define SENOIDE_H

class Senoide : public Funcao {
  public:
    Senoide() {};
    virtual ~Senoide(){}
    double func(double x) override { return sin(x)/x;}
  private:
    double a;
    double b;
    double c;
    double d;
};

#endif
