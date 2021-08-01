#include "ponto2D.hpp"
#ifndef PONTO3D_H
#define PONTO3D_H

class Ponto3D: public Ponto2D{
  public:
    Ponto3D(double xx = 0, double yy = 0, double zz=0);
    friend ostream& operator<< (ostream &op, const Ponto3D &p);
    Ponto3D& operator= (Ponto2D &p);
    void set(double nx=0, double ny=0, double nz=0);
    bool operator== (Ponto3D &p);
    double dist(Ponto3D p);
    double get_z();
  
  private:
    double z;
}; 

#endif