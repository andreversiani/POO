#include "funcao.hpp"

#ifndef QUADRATICA_H
#define QUADRATICA_H
class Quadratica : public Funcao {
  public:
    Quadratica(double a, double b, double c) {this->a = a; this->b = b; this->c = c;};
    virtual ~Quadratica(){}
    double func(double x) override {return (pow(x, 2) + b*x + c);}
  private:
    double a;
    double b;
    double c;
};
#endif