#include <iostream>
#include "Ponto.hpp"

using namespace std;

int main() {
  
  Ponto *p1 = new Ponto(4, 4);
  Ponto p2 = Ponto(3, 3);
  Ponto p3(p2);
  Ponto p4 = p3;

  cout << "ID de p1: " << p1->getID() << endl;
  cout << "ID de p2: " << p2.getID() << endl;
  cout << "ID de p3: " << p3.getID() << endl;
  cout << "ID de p4: " << p4.getID() << endl;
  
  cout << "p1: ";
  p1->print();
  cout << "p2: ";
  p2.print();
  cout << "p3: ";
  p3.print();
  cout << "p4: ";
  p4.print();

  cout << "Distancia p1 ate (0,0): " << p1->distToOrig() << endl;
  cout << "Distancia p2 ate (0,0): " << p2.distToOrig() << endl;
  cout << "Distancia p1 ate p2: " << p1->distTo(p2) << endl;

  delete p1;
}