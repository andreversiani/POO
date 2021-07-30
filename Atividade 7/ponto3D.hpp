#include "ponto2D.hpp"

class Ponto3D: public Ponto2D{
  public:
    Ponto3D(double xx = 0, double yy = 0, double zz=0);
    friend ostream& operator<< (ostream &op, const Ponto3D &p);
    Ponto3D& operator= (Ponto2D &p);
    void set(double nx=0, double ny=0, double nz=0);
    double get_z();
  
  private:
    double z;
}; 