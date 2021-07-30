#include "ponto3D.hpp"

Ponto3D::Ponto3D(double xx, double yy, double zz) {
  this->set(xx, yy, zz);
}

ostream& operator<< (ostream &op, Ponto3D &p) {
  op << endl;
  op << "x = " << p.get_x() << endl;
  op << "y = " << p.get_y() << endl;
  op << "z = " << p.get_z() << endl;
  return op;
};

Ponto3D& Ponto3D::operator= (Ponto2D &p) {
  this->set(p.get_x(), p.get_x(), 0);
  return *this;
};

double Ponto3D::get_z() {
  return this->z;
};

void Ponto3D::set(double xx, double yy, double zz) {
  this->Ponto2D::set(xx, yy);
  this->z = zz;
}