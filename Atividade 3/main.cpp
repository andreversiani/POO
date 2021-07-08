#include <iostream>
#include "Ponto.hpp"

using namespace std;

int main() {
  
  Ponto *p1 = new Ponto(4, 4);
  Ponto p2 = Ponto(3, 3);

  cout << "ID de p1: "<< p1->getID() << endl;
  cout << "ID de p2: " << p2.getID() << endl;
  
  cout << "p1: ";
  p1->print();
  cout << "p2: ";
  p2.print();

  cout << "Distancia p1 ate O: " << p1->distToOrig() << endl;
  cout << "Distancia p2 ate O: " << p2.distToOrig() << endl;
  cout << "Distancia p1 ate p2: " << p1->distTo(p2) << endl;

  delete p1;
}