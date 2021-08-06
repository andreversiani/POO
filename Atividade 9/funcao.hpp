#include <iostream>
#include <cmath>
using namespace std;


#ifndef FUNCAO_H
#define FUNCAO_H
class Funcao
{
    public:
      double getIntegral(double limiteInferior, double limiteSuperior, double intervalos);
      virtual ~Funcao(){}
    // funcao virtual representando a funcao cuja integral deve ser calculada
      virtual double func(double input) = 0;
};

#endif

