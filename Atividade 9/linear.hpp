#include "funcao.hpp"

#ifndef LINEAR_H
#define LINEAR_H
class Linear : public Funcao {
  public:
    Linear(double a, double b) {this->a = a; this->b = b;};
    virtual ~Linear(){}
    double func(double x) override {return (a*x + b);}
  private:
    double a;
    double b;
};

#endif

