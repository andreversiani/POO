#include "funcao.hpp"

double Funcao::getIntegral(double limiteInferior, double limiteSuperior, double intervalos) {
  double pontoInicial = limiteInferior;
  double pontoFinal = limiteSuperior;
  double altura = abs((pontoInicial - pontoFinal)/intervalos);
  double p2 = pontoInicial + altura;
  double area = 0;
  
  while(pontoInicial < pontoFinal) {
    double result = func(pontoInicial) + func(p2);
    area += result*altura/2;
    pontoInicial = p2;
    p2 += altura;
  }
  return area;
}