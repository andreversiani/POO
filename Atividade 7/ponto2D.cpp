#include<iostream>
#include <math.h>
#include "ponto2D.hpp"

using namespace std;

ostream& operator<< (ostream &op, const Ponto2D &p){
  op << endl;
  op << "x = " << p.x << endl;
  op << "y = " << p.y << endl;
  return op;
}

Ponto2D& Ponto2D::operator= (const Ponto2D &p){
  x = p.x;
  y = p.y;
  return *this;
}

double Ponto2D::dist(Ponto2D p) {
  return sqrt(pow(this->get_x() - p.get_x(), 2) + pow(this->get_y() - p.get_y(), 2));
}